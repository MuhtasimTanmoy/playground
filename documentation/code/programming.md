- Number range
	- -2^31 - 2^31 - 1 or -2*10^9 - 2*10^9 exact 2147483648
	- −2^63...2^63 −1 or −9·10^18...9·10^18 exact 9.223372e+18
	- int128_t −2^127...2^127 −1 or −10^38...10^38

-  Floating Point
	```c++
	if (abs(a-b) < 1e-9) { // a and b are equal }
	```
- ** Big INT **
	- String s;
	- stringstream ss(s);  
	- ss>>number;  
	- printf("%d", number);

- Binomial co efficient
	- `nCr` calculate
	- A binomial coefficient C(n, k) can be defined as the coefficient of `X ^ k` in the expansion of `(1 + X) ^ n`
	- `C(n, k)` also gives the number of ways, disregarding order, that k objects can be chosen from among n objects; more formally, 
	- The number of k-element subsets (or k-combinations) of an n-element set.

Co-prime Relatively prime
Chinese Remainder
(2 , 0.5), (10, 0.1), etc form reciprocals or multiplicative inverses

Modular Multiplicative Inverse of a number is the multiplicative inverse in the ring of integers modulo M, i.e. it is such a number which when multiplied with original number produces a product which modulo M gives unity.

Formulating, `α x ≡ 1 (mod M).`

The ring of integers correspond to the integers ranging [0, M-1]. Also, another point to be noted is that the Modular multiplicative inverse of a modulo M exists if and only if α and M are co-prime.

- Exponential
-  Sorting
	- If bound is known then counting sort in `o(n)`
-  Comparison Operator 
	- Sort based on first attribute then second
```c++
	struct P {
		int x, y;
		bool operator < (const P &p) {
			if ( x != p.x ) return x < p.x;
			else return y < p.y; 
		}
	};
```
- Built in
```c++
auto k = lower_bound(array, array + n, x) - array;
if ( k < n && array[k] == x ) {
	// x found at index k
}
```

```c++
auto a = lower_bound(array, array+n, x);
auto b = upper_bound(array, array+n, x);
cout << b-a << "\n";
```

```c++
auto r = equal_range(array, array+n, x);
cout << r.second-r.first << "\n";
```

## Problem 
Array max increasing subarray ignoring at most one.

- input
5
1 2 5 3 4

Step 1: We first compute longest increasing subarray ending at an index for every index in given array. We store these values in l[].  
Step 2: Then calculate longest increasing subarray starting at an index for every index in given array. We store these values in r[].  
Step 3: Update the answer ans = max ( ans, l[i-1] + r[i+1] + 1), when a[i-1] + 1 < a[i+1].

3 2 1 2 1
1 2 3 1 2

Use this for max elem in array  `int res =  *max_element(fr, fr + n);`

```c++
// size 10, initial va
vector<int> v(10);
// size 10, initial value 5
vector<int> v(10, 5);
```

- vector and string are just dynamic array
- Use .count() method.
Iterators are half open
`.end()` points to element after last elem to indicate null or not found val

```c++
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
random_shuffle(v.begin(), v.end());
```

lower bound upper bound only on set
This finds element nearest to x

```c++

auto it = s.lower_bound(x);

if (it == s.begin()) {
	cout << *it << "\n";
} else if (it == s.end()) {
	it--;
	cout << *it << "\n";
} else {
	int a = *it; it--;
	int b = *it;
	if (x-b < a-x) cout << b << "\n";
	else cout << a << "\n";
}

```

# Priority Queue
A priority queue maintains a set of elements. The supported operations are
insertion and, depending on the type of the queue, retrieval and removal of either
the minimum or maximum element. Insertion and removal take` O(logn)` time,
and retrieval takes `O(1)` time.

While an `ordered set` efficiently supports all the operations of a `priority queue`,
the benefit of using a priority queue is that it has smaller constant factors. A
priority queue is usually implemented using a `heap structure` that is much
simpler than a balanced binary tree used in an ordered set.

If we want to create a priority queue that supports finding and removing the
smallest element, we can do it as follows:

`priority_queue<int, vector<int>, greater<int>> q;`

- Complete Search
	- All subsequnce
	- Permutation
	- Queen problem
	- All grid visit
	- Meet in the middle

- Greedy Algorithm

In case of coins having multiplication greedy works
In case of duration scheduling always choose that end quick

In case of duration & deadline problem always duration matters deadline dont

Execute as fast as possible
Minimizing Sums

in case of plain absolute median
in case of square avg
Huffman coding

- Dynamic Programming
	- Correctness of complete search and efficiency of greedy algorithm
	- Finding an optimal solution: We want to find a solution that is as large as possible or as small as possible.
	- Counting the number of solutions: We want to calculate the total number of possible solutions.
	- Memoization

DP_MINIMUM_COIN_TO_REACH_TARGET

recursive
iterative
solve ( x ) = min( solve ( x − 1) + 1,
solve ( x − 3) + 1,
solve ( x − 4) + 1).

DP_ALL_WAYS_TO_REACH_TARGET

solve ( x ) = solve ( x − 1) +

solve ( x − 3) +

solve ( x − 4).

DP_MAXIMUM_SUBSEQUENCE

Let length ( k ) denote the length of the longest increasing subsequence that

ends at position k

DP_MAX_WEIGHT_SUM_GRID

corners added

then populate

KNAPSACK
The term knapsack refers to problems where a set of objects is given, and
subsets with some properties have to be found.

- Amortized analysis

2SUM
Nearest smaller element in left array
sliding window minimum
Prime factorization
Perfect number

Each number can be written as prime factors

84 = 1, 2, 3, 4, 6, 7, 12, 14, 21, 28, 42 and 84.

84 = 2^2 · 3^1 · 7^1

number of factors > (3 * 2 * 2) > tau

sum of factors > 2^3 - 1 · 3^2 - 1 · 7^2 -1 > sigma

product of factors > n^ num_0f_factors /2 > sigma

A number n is called a perfect number if n = σ ( n ) − n , i.e., n equals the sum

of its factors between 1 and n − 1

Density of primes > n/ ln(n)

Conjecture

Goldbach’s conjecture: Each even integer n > 2 can be represented as a

sum n = a + b so that both a and b are primes.


Twin prime conjecture: There is an infinite number of pairs of the form

{ p, p + 2}, where both p and p + 2 are primes

Legendre’s conjecture: There is always a prime between numbers n 2

and ( n + 1) 2 , where n is any positive integer.


lcb(a,b) = a*b/gcd(a,b)

Euclids GCD

Numbers a and b are coprime if gcd( a, b ) = 1.

Euler’s totient function φ ( n )

gives the number of coprime numbers to n between 1 and n . 

For example,

φ (12) = 4, because 1, 5, 7 and 11 are coprime to 12.
φ (12) = 2^(2-1) · (2 − 1) · 3^(1-1) · (3 − 1) = 4.

In modular arithmetic, the set of numbers is limited so that only numbers

0, 1, 2, . . . , m − 1 are used, where m is a constant.


# Keep

Border easy test populate
Then build up array
Matrix shortest path a to b
A point can be arrived at from up or left

Cutting sticks
Memoijation
at each point
Binary tree In Order always Sorts
tree child or height of each node o(n)
diameter two algo
fenwick tree
diagram lsb 
replaces suffix tree
better robin carp with bloom filter
all unique substring 
from lcs just find duplicates
longest common substring in 2...n

summation of range or assign one
anything is poorly doing is worth doing

next greater element 
https://www.geeksforgeeks.org/next-greater-element/

finding a loop in linked list

get first node
lowest common ancestor
exor / multiply / division / odd / even bitwise
exor to find any untracked in the middle elem
xor linked list
rightmost set bit (x xor x-1)
geeks : bitwise : last one
Segmented sieve


## Newton Rhapson

- Square root finding

	```c++
	float sqrtCustom(float x) {
		long double z = 1.0;
		for (int i = 1; i <= 15; i++) z -= ( z * z - x) / ( 2 * z );
		return z;
	}
	```

- **Formula**

Arithmatic Progression - n\* ( a + b ) / 2
Geometric Progression - ( b \* k - a ) / ( k - 1 )

- **Factorial**

- Binet Formula
- Finonacci factorial same for nth number

	```c++
	int fib_formula(int n) {
		float five = sqrt(5);
		return (pow((1 + five), n) + pow((1 - five), n)) / (pow(2, n) * five);
	}
	```

#### Binomial co efficient > nCr calculate

A binomial coefficient C(n, k) can be defined as the coefficient of X^k in the expansion of (1 + X)^n

C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects; more formally, the number of k-element subsets (or k-combinations) of an n-element set.

Co-prime Relatively prime 
Chinese Remainder

(2 , 0.5), (10, 0.1), etc form reciprocals or multiplicative inverses

Modular Multiplicative Inverse of a number is the multiplicative inverse in the ring of integers modulo M, i.e. it is such a number which when multiplied with original number produces a product which modulo M gives unity.
Formulating, α x ≡ 1 (mod M).
The ring of integers correspond to the integers ranging [0, M-1]. Also, another point to be noted is that the Modular multiplicative inverse of a modulo M exists if and only if α and M are co-prime.

- Exponential

```c++
void g(int n) {
	if (n == 1) return;
	g(n-1);
	g(n-1);
}

// 1+2+4+··· +2
// n−1 = 2^
// n −1 = O(2^n)
```

# Complete Search

All Subsequnce
Permutation
Queen problem
All grid visit
Meet in the middle

# Greedy Algorithm

In case of coins having multiplication greedy works
In case of duration scheduling always choose that end quick
In case of duration & deadline problem always duration matters deadline dont
Execute as fast as possible
Minimizing Sums
in case of plain absolute median
in case of square avg
Huffman coding

```c++
for (int x = 2; x <= n; x++) {
	if (sieve[x]) continue;
	for (int u = 2 * x; u <= n; u += x) 
		sieve[u] = x;
}

// o(nlogn)
```

# Modular Exponenentiation

```c++
int modpow(int x, int n, int m) {
	if (n == 0) return 1 % m;
	long long u = modpow(x, n/2, m);
	u = ( u * u ) % m;
	if ( n % 2 == 1) u = ( u * x ) % m;
	return u;
}
```

Fermates theorem,
`x ^ (m − 1) mod m = 1`

Eulers theorem
Modular inverse
