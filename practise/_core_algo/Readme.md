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

```
int fib_formula(int n)
{
	float five = sqrt(5);
	return (pow((1 + five), n) + pow((1 - five), n)) / (pow(2, n) * five);
}
```

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


