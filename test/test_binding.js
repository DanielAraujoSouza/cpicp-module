const CloudPartitioning = require("../lib/binding.js");
const assert = require("assert");

assert(CloudPartitioning, "The expected function is undefined");

function testBasic() {
    const numPartitions = 3
    const axis = 'x'
    const cloud = {
        width: 5,
        points: []
    }

    for (let i = 0; i < cloud.width; i++ ) {
        cloud.points.push({
            x: Math.random()*1000,
            y: Math.random()*1000,
            z: Math.random()*1000
        })
    }

    CloudPartitioning(cloud, numPartitions, axis).then(result => {
        const resultWidth = result.reduce((sum, e) => sum += e.width, 0);
        assert.strictEqual(resultWidth, cloud.width, "Sum of the resulting width is greater than the input width");
        result.forEach(e => {
            assert.strictEqual(e.points.length, e.width, "Subcloud with width different from the amount of points");
        });
    });
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");