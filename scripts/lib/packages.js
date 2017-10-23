// @flow

const { promisify } = require('util')
const path = require('path')
const fs = require('fs')
const child_process = require('child_process')
const chalk = require('chalk')
const semver = require('semver')
const retyped = require('reasonably-typed')

const readFile /*: (fname: string) => Promise<string> */ = promisify(
  fs.readFile
)
const readdir /*: (fname: string) => Promise<string[]> */ = promisify(
  fs.readdir
)
const exec = promisify(child_process.exec)

const TYPE_ROOT = path.join(__dirname, '..', '..', 'types')
const TS_ROOT = path.join(TYPE_ROOT, 'DefinitelyTyped', 'types')
const FLOW_ROOT = path.join(TYPE_ROOT, 'flow-typed', 'definitions', 'npm')

/*::
type Package = {
  name: string,
  moduleName: string,
  version: string,
  source: string
}
*/

async function getDefinitelyTypedFiles() {
  const tsFiles = await readdir(TS_ROOT)
  const packagePaths /*: { [packageName: string]: string } */ = tsFiles.reduce(
    (libs, libDir) => {
      return {
        ...libs,
        [libDir]: path.join(TS_ROOT, libDir, 'index.d.ts')
      }
    },
    {}
  )

  return packagePaths
}

async function compileDefinitelyTypedPackage(
  name /*: string */,
  packagePath /*: string */
) /*: Promise<?Package> */ {
  const packageSource = (await readFile(packagePath)).toString()

  try {
    const [_moduleName, bindingSource] = retyped.compile(
      packageSource,
      name,
      true
    )

    return {
      name,
      moduleName: name.replace(/\-/g, '_'),
      version: '1.0.0',
      source: bindingSource
    }
  } catch (e) {
    return undefined
  }
}

/** @deprecated */
async function getDefinitelyTypedPackages(
  cb /*: (name: string) => void */
) /*: Promise<Package[]> */ {
  const dtDir = await readdir(TS_ROOT)
  const dtFiles = []

  for (let packageName of dtDir) {
    try {
      const packageSourceFile = path.join(TS_ROOT, packageName, 'index.d.ts')
      const packageSource = (await readFile(packageSourceFile)).toString()

      if (cb) cb(packageName)

      const [_moduleName, bindingSource] = retyped.compile(
        packageSource,
        packageName,
        true
      )

      dtFiles.push({
        name: packageName,
        moduleName: packageName.replace(/\-/g, '_'),
        version: '1.0.0',
        source: bindingSource
      })
    } catch (e) {
      return []
    }
  }

  return dtFiles
}

/**
 * Returns the name and path of all FlowTyped packages
 */
async function getFlowTypedFiles() {
  const flowFiles = await readdir(FLOW_ROOT)
  const packagePaths /*: { [packageName: string]: string } */ = flowFiles.reduce(
    (libs, libDir) => {
      const libName = libDir.split('_v')[0]

      return {
        ...libs,
        [libName]: path.join(FLOW_ROOT, libDir)
      }
    },
    {}
  )

  return packagePaths
}

/**
 * Compile a FlowTyped package
 */
async function compileFlowTypedPackage(
  name /*: string */,
  packagePath /*: string */
) /*: Promise<?Package> */ {
  if (path.basename(packagePath).startsWith('@')) return undefined

  const allVersions = (await readdir(packagePath)).filter(f =>
    f.startsWith('flow')
  )
  const latestVersion = allVersions.sort()[allVersions.length - 1]
  const packageVersion = path
    .basename(packagePath)
    .split('_v')[1]
    .replace(/x/g, '0')
  const packageSourceFile =
    path.join(packagePath, latestVersion, path.basename(packagePath)) + '.js'
  const packageSource = (await readFile(packageSourceFile)).toString()

  try {
    const [moduleName, bindingSource] = retyped.compile(
      packageSource,
      packageSourceFile,
      true
    )

    return {
      name,
      moduleName,
      version: packageVersion,
      source: bindingSource
    }
  } catch (e) {
    return undefined
  }
}

/** @deprecated */
async function getFlowTypedPackages(cb /*: (name: string) => void */) {
  const packagePaths = await getFlowTypedFiles()

  const packages = await Promise.all(
    Object.entries(packagePaths).map(async ([name, packagePath]) => {
      if (typeof packagePath !== 'string') return undefined
      return compileFlowTypedPackage(name, packagePath)
    })
  )

  return packages.filter(p => p !== undefined)
}

function createPackageJson(
  package /*: Package */,
  previousVersion /*: string */
) {
  return JSON.stringify(
    {
      name: `@retypes/${package.name}`,
      version: previousVersion
        ? semver.inc(previousVersion, 'prerelease')
        : `${package.version}-0`,
      description: `Packaged ReasonML bindings for ${package.name}`,
      repository: 'https://github.com/rrdelaney/retypes',
      author: '',
      license: 'UNLICENSED'
    },
    null,
    2
  )
}

/**
 * Create a `bsconfig.json` given a package Object
 *
 * @param package Package object to base the resulting `bsconfig.json`
 */
function createBsConfig(package /*: Package */) {
  return JSON.stringify(
    {
      name: package.name,
      'bsc-flags': ['-bs-super-errors'],
      sources: [{ dir: 'src' }]
    },
    null,
    2
  )
}

/**
 * Runs a diff on a given directory
 *
 * Give a string representing the directory name,
 * and an object of keys/values with keys being the
 * file name and value being file contents you want to
 * diff against the existing directory
 *
 * @param dir Directory path to diff against
 * @param newFiles Files to diff against
 * @return True if the directories match, false if not
 */
async function diffDir(
  dir /*: string */,
  newFiles /*: { [filePath: string]: string } */
) {
  let files
  try {
    files = await readdir(dir)
  } catch (e) {
    return false
  }

  const diffs = await Promise.all(
    Object.entries(newFiles).map(async ([name, newContents]) => {
      try {
        const oldContents = (await readFile(path.join(dir, name))).toString()
        return newContents === oldContents
      } catch (e) {
        return false
      }
    })
  )

  return diffs.every(r => r === true)
}

/**
 * Publishes a package to npm
 *
 * @param dir Package directory to publish
 * @return Promise resolved when publishing is complete
 */
async function publish(dir /*: string */) {
  try {
    await exec(`npm publish --access public ${dir}`)
    console.log(`${chalk.green('✓')} Published ${dir}`)
  } catch (e) {
    console.error(`${chalk.red('✘')} Did not publish ${dir}`)
    console.error(e.message)
  }
}

function deprecated(fn /*: Function */) {
  return (...args /*: any */) => {
    console.error(chalk.red(`\nFunction "${fn.name}" is deprecated.`))

    return fn(...args)
  }
}

module.exports = {
  getDefinitelyTypedFiles,
  compileDefinitelyTypedPackage,
  getDefinitelyTypedPackages: deprecated(getDefinitelyTypedPackages),
  getFlowTypedFiles,
  compileFlowTypedPackage,
  getFlowTypedPackages: deprecated(getFlowTypedPackages),
  createPackageJson,
  createBsConfig,
  diffDir,
  publish
}
