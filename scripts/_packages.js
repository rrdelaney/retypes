const { promisify } = require('util')
const path = require('path')
const fs = require('fs')
const retyped = require('reasonably-typed')

const readFile = promisify(fs.readFile)
const readdir = promisify(fs.readdir)

const FLOW_ROOT = path.join(__dirname, '..', 'flow-typed', 'definitions', 'npm')

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
        const bindingSource = retyped.compile(packageSource, packageSourceFile)
        return { name, version: packageVersion, source: bindingSource }
      } catch (e) {
        return undefined
      }
    })
  )

  return packages.filter(p => p !== undefined)
}

function createPackageJson(package) {
  return JSON.stringify(
    {
      name: `@retypes/${package.name}`,
      version: package.version,
      description: `Packaged ReasonML bindings for ${package.name}`,
      repository: 'https://github.com/rrdelaney/retypes',
      author: '',
      license: 'UNLICENSED'
    },
    null,
    2
  )
}

module.exports = { getFlowTypedPackages, createPackageJson }
