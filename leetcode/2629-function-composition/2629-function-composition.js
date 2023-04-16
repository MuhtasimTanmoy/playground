/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(fns) {
	return function(x) {
        fns.slice().reverse().forEach(fn => { x = fn(x); } )
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */