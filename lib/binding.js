const addon = require('../build/Release/cpicp-module-native')
//const addon = require('../build/Debug/cpicp-module-native');

/**
 * Particiona, de forma assíncrona, uma nuvem de pontos.
 * @param {object} cloud Objeto correspondente a nuvem que será particionada.
 * @returns {Promise} Resolve: Vetor contendo as nuvem particionadas.
 */
exports.CloudPartitioning =
  addon.CloudPartitioning /*(cloud, numPartitions, axis)*/

/**
 * Particiona, de forma síncrona, uma nuvem de pontos.
 * @param {object} cloud Objeto correspondente a nuvem que será particionada.
 * @returns {Array} Vetor contendo as nuvem particionadas.
 */
exports.CloudPartitioningSync =
  addon.CloudPartitioningSync /*(cloud, numPartitions, axis)*/
