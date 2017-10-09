// @flow

const { promisify } = require('util')
const rimraf = promisify(require('rimraf'))

rimraf('packages')
