const test = require('tape')
const cpicp = require('../lib/binding.js')
const utils = require('./utils')

console.log(cpicp)

test('Cloud Partitioning', async (t) => {
  t.assert(cpicp.CloudPartitioning, 'CloudPartitioning function defined')

  const numPartitions = 3
  const axis = 'x'
  const cloud = utils.generateCloud(5)

  const loaded = await cpicp.CloudPartitioning(cloud, numPartitions, axis)
  const resultWidth = loaded.reduce((sum, e) => (sum += e.numpts), 0)
  t.deepEqual(resultWidth, cloud.numpts, 'Correctly partitioned asynchronously')

  t.assert(
    cpicp.CloudPartitioningSync,
    'CloudPartitioningSync function defined'
  )

  const loadedSync = await cpicp.CloudPartitioningSync(
    cloud,
    numPartitions,
    axis
  )
  const resultWidthSync = loaded.reduce((sum, e) => (sum += e.numpts), 0)
  t.deepEqual(
    resultWidthSync,
    cloud.numpts,
    'Correctly partitioned synchronously'
  )

  t.end()
})
