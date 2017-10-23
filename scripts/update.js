// @flow

const { promisify } = require('util')
const path = require('path')
const fs = require('fs')
const rimraf = promisify(require('rimraf'))
const chalk = require('chalk')
const ora = require('ora')
const { default: Worker } = require('jest-worker')
/*:: import typeof * as Lib from './lib/packages' */

const lib = new Worker(require.resolve('./lib/packages'))

const mkdir /*: (dirName: string) => void */ = promisify(fs.mkdir)
const writeFile /*: (fname: string, data: string | Buffer) => void */ = promisify(
  fs.writeFile
)

async function run() {
  const spinner = ora('Compiling packages')
  spinner.start()

  const setName = type => name => {
    spinner.text = `Compiling ${type}:${name}`
  }

  const [flowTypedPackages, definitelyTypedPackages] = await Promise.all([
    (async () => {
      const flowTypedFiles = await lib.getFlowTypedFiles()

      return (await Promise.all(
        Object.entries(flowTypedFiles).map(([name, packagePath]) => {
          if (typeof packagePath !== 'string')
            throw new Error('expected string')
          setName('ft')(name)
          return lib.compileFlowTypedPackage(name, packagePath)
        })
      )).filter(p => !!p)
    })(),

    (async () => {
      const definitelyTypedFiles = lib.getDefinitelyTypedFiles()

      return (await Promise.all(
        Object.entries(definitelyTypedFiles).map(([name, packagePath]) => {
          if (typeof packagePath !== 'string')
            throw new Error('expected string')
          setName('dt')(name)
          return lib.compileDefinitelyTypedPackage(name, packagePath)
        })
      )).filter(p => !!p)
    })()
  ])

  console.error(definitelyTypedPackages.length)

  const packageSet = new Set()
  const p = [
    ...flowTypedPackages,
    ...definitelyTypedPackages
  ].filter(({ name }) => {
    if (packageSet.has(name)) return false

    packageSet.add(name)
    return true
  })

  spinner.succeed(`Compiled ${p.length} packages`)

  const allPackages = await Promise.all(
    p.map(async package => {
      // TODO: add previous version to lib.createPackageJson
      const packageJSON = await lib.createPackageJson(package, '')
      const bsConfig = await lib.createBsConfig(package)

      const newDir = {
        'package.json': packageJSON,
        'bsconfig.json': bsConfig,
        [`src/${package.name}.re`]: package.source
      }

      if (await lib.diffDir(`packages/${package.name}`, newDir))
        return undefined

      return {
        ...package,
        packageJSON,
        bsConfig
      }
    })
  )

  const updatedPackages = await Promise.all(
    allPackages.filter(p => p !== undefined)
  )

  updatedPackages.forEach(async package => {
    if (!package) return
    const oldVersion = JSON.parse(package.packageJSON).version
    package.packageJSON = lib.createPackageJson(package, oldVersion)

    await rimraf(`packages/${package.name}`)
    await mkdir(`packages/${package.name}`)
    await mkdir(`packages/${package.name}/src`)

    await Promise.all([
      writeFile(`packages/${package.name}/package.json`, package.packageJSON),
      writeFile(`packages/${package.name}/bsconfig.json`, package.bsConfig),
      writeFile(
        `packages/${package.name}/src/${package.moduleName}.re`,
        package.source
      )
    ])

    console.log(`${chalk.green('✓')} Wrote packages/${package.name}`)
  })

  lib.end()
}

run().catch(e => console.error(chalk.red(e)))
