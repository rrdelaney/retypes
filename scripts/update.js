const { promisify } = require('util')
const path = require('path')
const fs = require('fs')
const rimraf = promisify(require('rimraf'))
const chalk = require('chalk')
const ora = require('ora')
const {
  getDefinitelyTypedPackages,
  getFlowTypedPackages,
  createPackageJson,
  createBsConfig,
  diffDir
} = require('./_packages')

const mkdir = promisify(fs.mkdir)
const writeFile = promisify(fs.writeFile)

async function run() {
  const spinner = ora('Compiling packages')
  spinner.start()

  const setName = type => name => {
    spinner.text = `Compiling ${type}:${name}`
  }

  const [flowTypedPackages, definitelyTypedPackages] = await Promise.all([
    // getFlowTypedPackages(setName('ft')),
    Promise.resolve([]),
    getDefinitelyTypedPackages(setName('dt'))
  ])

  const packageMap = new Map()
  const p = [
    ...flowTypedPackages,
    ...definitelyTypedPackages
  ].filter(({ name }) => {
    if (packageMap.get(name)) return false

    packageMap.set(name, true)
    return true
  })

  spinner.succeed(`Compiled ${p.length} packages`)

  const allPackages = await Promise.all(
    p.map(async package => {
      const packageJSON = createPackageJson(package)
      const bsConfig = createBsConfig(package)

      const newDir = {
        'package.json': packageJSON,
        'bsconfig.json': bsConfig,
        [`src/${package.name}.re`]: package.source
      }

      if (await diffDir(`packages/${package.name}`, newDir)) return undefined

      return {
        ...package,
        packageJSON,
        bsConfig
      }
    })
  )

  const updatedPackages = allPackages.filter(p => p !== undefined)

  updatedPackages.forEach(async package => {
    const oldVersion = JSON.parse(package.packageJSON).version
    package.packageJSON = createPackageJson(package, oldVersion)

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
}

run().catch(e => console.error(chalk.red(e)))
