const { promisify } = require('util')
const path = require('path')
const fs = require('fs')
const {
  getFlowTypedPackages,
  createPackageJson,
  createBsConfig
} = require('./_packages')

const mkdir = promisify(fs.mkdir)
const writeFile = promisify(fs.writeFile)

async function run() {
  try {
    await mkdir('packages')
  } catch (e) {}

  const p = await getFlowTypedPackages()

  await Promise.all(
    p.map(async package => {
      await mkdir(`packages/${package.name}`)
      await mkdir(`packages/${package.name}/src`)
      const packageJSON = createPackageJson(package)
      const bsConfig = createBsConfig(package)

      await Promise.all([
        writeFile(`packages/${package.name}/package.json`, packageJSON),
        writeFile(`packages/${package.name}/bsconfig.json`, bsConfig),
        writeFile(
          `packages/${package.name}/src/${package.name}.re`,
          package.source
        )
      ])
    })
  )

  const packageNames = p.map(({ name }) => name)
  await writeFile(
    path.join(__dirname, '..', 'docs', 'generated-packages.json'),
    JSON.stringify({
      packages: packageNames
    })
  )
}

run().catch(e => console.error(e.message))
