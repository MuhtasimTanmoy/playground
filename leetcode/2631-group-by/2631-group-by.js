/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const ans = {}
    for(let e of this) {
        const key = fn(e)
        if (!ans.hasOwnProperty(key)) ans[key] = [];
        ans[key].push(e)
    }
    return ans
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */