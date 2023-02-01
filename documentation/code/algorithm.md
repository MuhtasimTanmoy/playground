# Algorithm
- Split code to modules
- Test each one
- Connect all
- Delete everything and begin again with fresh eyes. You’ll be dumbfounded at how effective this is

# String
- Aho Corasick
- KMP
- Rolling hash to match pattern

# Range Query
- sum q `( a, b )`
- calculate the sum of values in range `[ a, b ]`

# Prefix Sum
- min q `( a, b )`
- find the minimum value in range `[ a, b ]`

# Sparse Tree 
- Perform range queries in `0(1)`
- others `logn`
- Must be on immutable arrays
- if changes then whole precomputation
- `max q(a, b)`, find the maximum value in range [a, b]

# Difference Array

- N th polite number
    - summation of consequtive positive number
- fun(n) = n + floor(log2(n+log2(n)))
- Any number can be represented in summands its bit represenetation > (1101) > ceil(log2(x))


# Bit Manipulation 
```c++
// 5328
// 00000000000000000001010011010000
__builtin_clz(x) << "\n"; // 19
__builtin_ctz(x) << "\n"; // 4
__builtin_popcount(x) << "\n"; // 5
__builtin_parity(x) << "\n"; // 1
```

# Z algorithm
- Study later

# Range update
- [Convex Hull](https://leetcode.com/problems/largest-triangle-area/discuss/1923968/C%2B%2B-2-solutions-or-improved-one-with-0ms)

- Binary Search noraml is flawd
	- https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
	- `int mid = low + ((high - low) / 2);`
	- `let mid = (low & high) + ((low ^ high) >> 1);`

# Remark
- Binary Search noraml is flawd
	- https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
	- `int mid = low + ((high - low) / 2);`
	- `let mid = (low & high) + ((low ^ high) >> 1);`
