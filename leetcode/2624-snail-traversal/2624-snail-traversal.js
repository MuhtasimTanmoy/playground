/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount * colsCount != this.length) return [];
    let res = [];
    for (let j = 0; j < rowsCount; j++) res.push([]);
    for (let i = 0; i < colsCount; i++)
        for (let j = 0; j < rowsCount; j++) {
            let item = this[i * rowsCount + j];
            if (i & 1) res[rowsCount - j - 1].push(item); else res[j].push(item);
        }
    return res;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */