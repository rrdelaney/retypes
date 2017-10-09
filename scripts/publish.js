// @flow

const { promisify } = require('util')
const fs = require('fs')
const { publish } = require('./lib/packages')

const readdir /*: (dirName: string) => Promise<string[]> */ = promisify(
  fs.readdir
)

async function run() {
  const packages = await readdir('packages')

  await Promise.all(packages.map(p => publish(`packages/${p}`)))
}

run().catch(e => console.error(e.message))
