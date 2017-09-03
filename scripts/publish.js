const { promisify } = require('util')
const fs = require('fs')
const pLimit = require('p-limit')
const { publish } = require('./_packages')

const readdir = promisify(fs.readdir)
const limit = pLimit(5)

async function run() {
  const packages = await readdir('packages')

  await Promise.all(packages.map(p => limit(() => publish(`packages/${p}`))))
}

run().catch(e => console.error(e.message))
