/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    if (n == 0) return arr;
    let answer = [];
    for (let i = 0; i < arr.length; i++) 
        if (n && Array.isArray(arr[i])) answer.push(...flat(arr[i], n - 1));
        else answer.push(arr[i]);
    return answer;
};