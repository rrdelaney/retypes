const { promisify } = require('util')
const path = require('path')
const fs = require('fs')
const child_process = require('child_process')
const chalk = require('chalk')
const semver = require('semver')
const retyped = require('reasonably-typed')

const readFile = promisify(fs.readFile)
const readdir = promisify(fs.readdir)
const exec = promisify(child_process.exec)

const FLOW_ROOT = path.join(__dirname, '..', 'flow-typed', 'definitions', 'npm')
const TS_ROOT = path.join(__dirname, '..', 'DefinitelyTyped', 'types')

async function getDefinitelyTypedPackages() {
  const dtFiles = await readdir(TS_ROOT)
}

async function getFlowTypedPackages() {
  const flowFiles = await readdir(FLOW_ROOT)
  const packagePaths = flowFiles.reduce((libs, libDir) => {
    const libName = libDir.split('_v')[0]

    return {
      ...libs,
      [libName]: path.join(FLOW_ROOT, libDir)
    }
  }, {})

  const packages = await Promise.all(
    Object.entries(packagePaths).map(async ([name, packagePath]) => {
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
        path.join(packagePath, latestVersion, path.basename(packagePath)) +
        '.js'
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
    })
  )

  return packages.filter(p => p !== undefined)
}

function createPackageJson(package, previousVersion) {
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

function createBsConfig(package) {
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

async function diffDir(dir, newFiles) {
  const files = await readdir(dir)

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

async function publish(dir) {
  try {
    await exec(`npm publish --access public ${dir}`)
    console.log(`${chalk.green('✓')} Published ${dir}`)
  } catch (e) {
    console.error(`${chalk.red('✘')} Did not publish ${dir}`)
    console.error(e.message)
  }
}

module.exports = {
  getFlowTypedPackages,
  createPackageJson,
  createBsConfig,
  diffDir,
  publish
}
