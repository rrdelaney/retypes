const { promisify } = require('util')
const fs = require('fs')
const { getFlowTypedPackages, createPackageJson } = require('./_packages')

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
      const packageJSON = createPackageJson(package)

      await Promise.all([
        writeFile(`packages/${package.name}/package.json`, packageJSON),
        writeFile(`packages/${package.name}/${package.name}.re`, package.source)
      ])
    })
  )
}

run().catch(e => console.error(e.message))
