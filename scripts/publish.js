const { promisify } = require('util')
const fs = require('fs')
const { publish } = require('./_packages')

const readdir = promisify(fs.readdir)

async function run() {
  const packages = await readdir('packages')

  await Promise.all(
    packages.map(async p => {
      await publish(`packages/${p}`)
    })
  )
}

run().catch(e => console.error(e.message))
