/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filtered_arr = [];
    for (let i = 0; i < arr.length; i++) 
        if (fn(arr[i], i))
            filtered_arr.push(arr[i])
    return filtered_arr;
};