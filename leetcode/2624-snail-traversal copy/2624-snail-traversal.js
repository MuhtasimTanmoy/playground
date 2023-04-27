/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(row, col) {
    if (row * col != this.length) return [];
    let res = [];
    for (let j = 0; j < row; j++) res.push([]);
    for (let i = 0; i < col; i++)
        for (let j = 0; j < row; j++) {
            let index = (i & 1) ? row - j - 1: j, 
                item = this[i * row + j];
            res[index].push(item);
        }
    return res;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */