# @retypes

Index of curated and automatically generated JS bindings for ReasonML

This repo consists of:
* scripts to generate packages
* documentation / search website
* generated package definitions

# Scripts

There are several scripts here. You can run each with `node scripts/<script-name>.js`

### scripts/bootstrap.js

Sets up the initial implementation of each package. **DON'T RUN ME.** This
script was only run for the first set up of the repo.

### scripts/clean.js

Deletes all packages. **DON'T RUN ME.** If all packages are removed we would need to
set everything up again, and manually put in version numbers of packages.

### scripts/publish.js

Will try to publish every library in `packages/`.

### scripts/update.js

Runs the code generation for each package, and if it's different replace the
old package and increment the version.
