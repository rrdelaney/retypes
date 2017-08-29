const { promisify } = require('util')
const path = require('path')
const fs = require('fs')

const readFile = promisify(fs.readFile)
const readdir = promisify(fs.readdir)

const FLOW_ROOT = path.join(__dirname, '..', 'flow-typed', 'definitions', 'npm')

async function getFlowTypedFiles() {
  const flowFiles = await readdir(FLOW_ROOT)

  return flowFiles.reduce((libs, libDir) => {
    const libName = libDir.split('_v')[0]

    return {
      ...libs,
      [libName]: path.join(FLOW_ROOT, libDir)
    }
  }, {})
}

async function run() {
  console.log(await getFlowTypedFiles())
}

run().catch(e => console.error(e.message))
