const { promisify } = require('util')
const path = require('path')
const fs = require('fs')
const rimraf = promisify(require('rimraf'))
const chalk = require('chalk')
const {
  getFlowTypedPackages,
  createPackageJson,
  createBsConfig,
  diffDir
} = require('./_packages')

const mkdir = promisify(fs.mkdir)
const writeFile = promisify(fs.writeFile)

async function run() {
  const p = await getFlowTypedPackages()

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
      writeFile(`packages/${package.name}/package.json`, packageJSON),
      writeFile(`packages/${package.name}/bsconfig.json`, bsConfig),
      writeFile(
        `packages/${package.name}/src/${package.moduleName}.re`,
        package.source
      )
    ])

    console.log(`${chalk.green('✓')} Wrote packages/${package.name}`)
  })
}

run().catch(e => console.error(e.message))
