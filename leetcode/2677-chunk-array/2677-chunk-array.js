/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    let cnt = 1;
    let res = [], chunk = [];
    for (const i of arr) {
        chunk.push(i);
        if (cnt % size == 0) {
            res.push(chunk);
            chunk = [];
        }
        cnt++;
    }
    if (chunk.length) res.push(chunk);
    return res;
};
