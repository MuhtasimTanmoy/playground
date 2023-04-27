/**
 * @param {Function} fn
 */
class TrieNode {
    constructor() {
        this.hasResult = false;
        this.val = undefined;
        this.children = new Map();
    }
}

function memoize(fn) {
    let cache = new TrieNode();
    return function (...args) {
        let now = cache;
        for (let arg of args) {
          let child = now.children.get(arg);
          if (!child) {
            child = new TrieNode();
            now.children.set(arg, child);
          }
          now = child;
        }
        if (!now.hasResult) {
          now.val = fn(...args);
          now.hasResult = true;
        }
        return now.val;
    }
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */