const cpicp = require('../lib/binding.js')

// Argumentos de entrada
const cloud = {
  numpts: 5,
  points: [
    { x: 1, y: 1, z: 1 },
    { x: 2, y: 2, z: 2 },
    { x: 3, y: 3, z: 3 },
    { x: 4, y: 4, z: 4 },
    { x: 5, y: 5, z: 5 },
    { x: 6, y: 6, z: 6 },
    { x: 7, y: 7, z: 7 },
    { x: 8, y: 8, z: 8 },
    { x: 9, y: 9, z: 9 },
  ],
}
const numPartitions = 5
const axis = 'y'

// Executa o particionamento
const clouds = cpicp.CloudPartitioningSync(cloud, numPartitions, axis)
console.log(clouds)
