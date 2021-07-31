function randomNumber(min, max) {
  return Math.random() * (max - min) + min
}

function generateCloud(len, range = 100) {
  cloud = {
    numpts: len,
    points: new Array(len),
  }

  for (let i = 0; i < len; i++) {
    cloud.points[i] = {
      x: randomNumber(-range, range),
      y: randomNumber(-range, range),
      z: randomNumber(-range, range),
    }
  }

  return cloud
}

module.exports = {
  randomNumber,
  generateCloud,
}
