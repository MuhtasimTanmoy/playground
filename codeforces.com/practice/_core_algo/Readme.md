- **Number range**

> -2^31 - 2^31 or -2*10^9 - 2*10^9 exact 2147483648

> −2^63...2^63 −1 or −9·10^18...9·10^18 exact 9.223372e+18

> \_\_int128_t −2^127...2^127 −1 or about −10^38...10^38

- **Floating point**

```
if (abs(a-b) < 1e-9) {
// a and b are equal
}
```

- **Formula**

Arithmatic Progression - n\* ( a + b ) / 2

Geometric Progression - ( b \* k - a ) / ( k - 1 )

- **Factorial**

Binet formula

Finonacci factorial same for nth number

```
int fib_formula(int n)
{
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





- **Exponential**

```
void g(int n) {
if (n == 1) return;
g(n-1);
g(n-1);
}
```

> 1+2+4+··· +2
> n−1 = 2^
> n −1 = O(2^n
> ).

- **Sorting**

> If bound is known then counting sort in o(n)

- **Comparison Operator** - Sort based on first attribute then second

      	```
      		struct P { int x, y;
      		bool operator<(const P &p)
      		{
      		if (x != p.x)
      		return x < p.x;
      		else
      		return y < p.y; }
      		};
      	```

      	- Binary Search
      		```
      			int a = 0, b = n-1;
      			while (a <= b) {
      				int k = (a+b)/2;
      				if (array[k] == x) {
      				// x found at index k
      				}
      				if (array[k] > x) b = k-1;
      				else a = k+1;
      			}
      		```

      	- Built In

      		```
      			auto k = lower_bound(array,array+n,x)-array;
      				if (k < n && array[k] == x) {
      				// x found at index k
      			}
      		```

      		```
      			auto a = lower_bound(array, array+n, x);
      			auto b = upper_bound(array, array+n, x);
      			cout << b-a << "\n";
        	```

      		```
      			auto r = equal_range(array, array+n, x);
      			cout << r.second-r.first << "\n";

      		```

- **Data Structures**

      	- Easy Syntax

      	```
      		for (auto x : v) {
      			cout << x << "\n";
      			}
      		vector<int> v = {2,4,2,5,1};

      		// size 10, initial va
      		vector<int> v(10);

      		// size 10, initial value 5
      		vector<int> v(10, 5);
      	```

      	vector and string are just dynamic array

      	```
      		set<int> s;
      		unordered_set
      		multiset
      		unordered_multiset

      	```

      	Map

      	> Use .count() method
      		Iterators are half open
      			.end() points to element after last elem to indicate null or not found val


    ```
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    random_shuffle(v.begin(), v.end());
    ```

    	lower bound upper bound only on set

    	This finds element nearest to x

    **Sample Problem**

    ```
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

**Bitset**
Amazing data structure
bitset<10> s(string("0010011010")

**Deque**

**Stack**

**Queue**

**Priority Queue**

A priority queue maintains a set of elements. The supported operations are
insertion and, depending on the type of the queue, retrieval and removal of either
the minimum or maximum element. Insertion and removal take O(logn) time,
and retrieval takes O(1) time.

While an ordered set efficiently supports all the operations of a priority queue,
the benefit of using a priority queue is that it has smaller constant factors. A
priority queue is usually implemented using a heap structure that is much
simpler than a balanced binary tree used in an ordered set.

If we want to create a priority queue that supports finding and removing the
smallest element, we can do it as follows:

> priority_queue<int,vector<int>,greater<int>> q;

**Sample Probelm 2**

Two list containing same element

```
ordered set slow
unordered set sligtyly fast
sorting checking very fast

```

### Complete Search

All subsequnce
Permutation

Queen problem
All grid visit

Meet in the middle

### Greedy Algorithm

In case of coins having multiplication greedy works

In case of duration scheduling always choose that end quick

In case of duration & deadline problem always duration matters deadline dont

Execute as fast as possible

Minimizing Sums

in case of plain absolute median

in case of square avg

Huffman coding

### Dynamic Programming

Correctness of complete search and efficiency of greedy algorithm

- Finding an optimal solution: We want to find a solution that is as large
  as possible or as small as possible.
- Counting the number of solutions: We want to calculate the total num-
  ber of possible solutions.

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

### Amortized Analysis

2SUM

Nearest smaller element in left array

sliding window minimum

### Range query

• sum q ( a, b ): calculate the sum of values in range [ a, b ]

# Prefix Sum

• min q ( a, b ): find the minimum value in range [ a, b ]

# Sparse Tree > Perform range queries in 0(1) > others logn
Must be on immutable arrays > if changes then whole precomputation

• max q ( a, b ): find the maximum value in range [ a, b ]

# Range Update
# Difference Array

N th polite number > summation of consequtive positive number

fun(n) = n + floor(log2(n+log2(n)))

Any number can be represented in summands its bit represenetation > (1101) > ceil(log2(x))

# Fenwick tree > 

all operations logn 
update > range sum > 

# segment tree

all operations logn
update > range sum > min > max



## Bit Manipulation

5328; // 00000000000000000001010011010000
__builtin_clz(x) << "\n"; // 19
__builtin_ctz(x) << "\n"; // 4
__builtin_popcount(x) << "\n"; // 5
__builtin_parity(x) << "\n"; // 1




# Z algorithm





## Advanced

Prime factorization

Perfect number

Each number can be written > as prime factors

84 = 1, 2, 3, 4, 6, 7, 12, 14, 21, 28, 42 and 84.

84 = 2^2 · 3^1 · 7^1

number of factors > (3 * 2 * 2) > tau 

sum of factors >  2^3 - 1 · 3^2 - 1  · 7^2 -1 > sigma

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


```
for (int x = 2; x <= n; x++) {
if (sieve[x]) continue;
for (int u = 2*x; u <= n; u += x) {
sieve[u] = x;
}
}


o(nlogn)

```

The algorithm builds an array sieve whose positions 2, 3, . . . , n are used. The
value sieve [ k ] = 0 means that k is prime, and the value sieve [ k ] 6= 0 means that
k is not a prime and one of its prime factors is sieve [ k ].



lcb(a,b) = a*b/gcd(a,b)

EUclids GCD

Numbers a and b are coprime if gcd( a, b ) = 1.

Euler’s totient function φ ( n )
gives the number of coprime numbers to n between 1 and n . For example,
φ (12) = 4, because 1, 5, 7 and 11 are coprime to 12.

φ (12) = 2^(2-1) · (2 − 1) · 3^(1-1) · (3 − 1) = 4.

In modular arithmetic, the set of numbers is limited so that only numbers
0, 1, 2, . . . , m − 1 are used, where m is a constant.

# modular Exponenentiation

```
int modpow(int x, int n, int m) {
if (n == 0) return 1%m;
long long u = modpow(x,n/2,m);
u = (u*u)%m;
if (n%2 == 1) u = (u*x)%m;
return u;
}

```

Fermates theorem

x ^ (m − 1) mod m = 1

Eulers theorem

Modular inverse



