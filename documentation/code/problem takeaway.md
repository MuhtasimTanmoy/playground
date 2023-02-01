# Problem Takeaway
- Two list containing same element
    - ordered set slow
    - unordered set sligtyly fast
    - sorting checking very fast

- kth smallest, largest
    - priority_queue

- Map to different domain always val freq then freq val
- `bit / fenwick` - in case of unique use set approach

- Find missing Item
	- Just sum and substract
	
- Dynamic Programming
	- To take or not take

- For `palindrome` findings.
    - Switch to an index, then go both ways.
    - Otherwise, many more possible way to go.

    ```c++
    auto getlength = [&] (int l, int r) {
        while ( l >= 0 && r < length && s[l] == s[r] ) {
            -- l;
            ++ r;
        }
        return r -l - 1;
    };
    
    int current_pallindrome = 
    max(getlength(i, i), getlength(i, i+1));
    
    if (current_pallindrome > longest_pallindrome) {
        longest_pallindrome = current_pallindrome;
        start = i - (longest_pallindrome -1) /2;
    }
    ```
- For longest non repeating substring
    - Keeping `char` to `index` mapping

<br/>

- Two sorted array traversal
    ```c++
    int num1Index = 0;
    int num2Index = 0;
    auto extractNext = [&]() -> int {
        if (num1Index >= nums1.size()) {
            num2Index++;
            return nums2[num2Index - 1];
        }
        if (num2Index >= nums2.size()) {
            num1Index++;
            return nums1[num1Index - 1];
        }
        if (nums1[num1Index] <= nums2[num2Index]) {
            num1Index++;
            return nums1[num1Index - 1];
        } else {
            num2Index++;
            return nums2[num2Index - 1];
        }
    };
    ```

- Number pallindrome

    ```c++
    int reversed = 0;
    // Reverses the whole number. But can cause INT_MAX error.
    while(x) {
        reversed = reversed * 10 + x % 10;
        x = x / 10;
    }
    // It is solved by this.
    bool isPalindrome(int x) {
        if ( x < 0 || ( x % 10 == 0 && x != 0)) return false;
        int reversed = 0;
        while(x > reversed) {
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }
        return x == reversed || x == reversed / 10;
    }
    ```

- Prime Factorization
    ```c++
    // Generating for 1000 numbers
    // input should be root of n
    bool[] generateSieve(int n) {
        bool isPrime[n + 1];
        memset(isPrime, true, sizeof(isPrime));
        for ( int i = 2; i * i <= n; i++ )
            if ( isPrime[i] ) 
                for(int p = i * i; p <= n; p += i) isPrime[p] = false;
        return isPrime;
    }

    auto getPrimeFactors = [&](int n) -> vector<int> {
        vector<int> primeFactors;
        for(int i = 2; i * i <= n; i+=1 ) {
            if ( n % i == 0 ) {
                if (isPrime[i]) primeFactors.push_back(i);
                if (isPrime[n / i]) primeFactors.push_back(n / i);
            }
        }
        return primeFactors;
    };
    ```

- All subset

    ```c++
    void allSubSet(vector<int>& nums, 
                vector<int> current,
                int index,
                vector<vector<int>>& subsets) {
        
        if (index == nums.size()) { 
            subsets.push_back(current);
            return;
        }
        
        allSubSet(nums, current, index + 1, subsets);
        current.push_back(nums[index]);
        allSubSet(nums, current, index + 1, subsets);
        current.pop_back();
    }

    vector<vector<int>> subsets;
    vector<int> current;
    allSubSet(nums, current, 0, subsets);
    ```

- Divide and conquer design pattern
- Rote learning will lead to perfect solution to wrong problem

![](./Screen/Interview%20Guide.png)

- Google `c++` Style Guide
    - Input arguments to functions are either values or const references. 
    - Never allow non-const references.
- Reverse while checking INT_MAX, INT_MIN

    ```c++
    INT_MAX = 2147483647
    INT_MIN = -2147483648
    int num = neg_num % 10 // gives negative
    ```

- Rotate array
    ```c++
    // Extra Space
    class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            vector<int> cache = nums;
            auto swapWithOffset = [&](int first) {
                int num = cache[first];
                int replaceToIndex = (first + k ) % nums.size();
                nums[ replaceToIndex ] = num;
            };
            for( int i = 0; i< nums.size(); i++) swapWithOffset(i);
        }
    };
    ```

    ```c++
    // Cut the last part and reinsert
    vector<int> temp = 
    vector<int>(nums.begin() + n - k % n, nums.end());
    //modulus handles k>n and subtract by n for last k elements
    if ( k % n ) nums.resize(n - k % n);
    nums.insert(nums.begin(), temp.begin(), temp.end()); 
    //insert temp in the beginning of nums  
    // No space
    // Use rotation, the last part will be first anyway
    ```

Supporse, k = 2
- Data: 1,2,3,4,5,6,7
- Full Reverse: 7,6,5,4,3,2,1
- Reverse 0 to k-1: 6,7 ...
- Reverse k to arr.length-1 : 1,2,3,4,5
- Rotated arr = 6,7,1,2,3,4,5

- Contain Duplicate and their index in certain range
    - Can think in two dimensions, sort using one, check index

    ```c++
    class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            map<int, vector<int>> m;
            for(int i=0; i < nums.size(); i++ ) {
                int occuranceCount = m[nums[i]].size();
                if (occuranceCount) {
                    // Extracting the last index inserted
                    int k1 = m[nums[i]][occuranceCount-1];
                    if ( (i - k1) <= k ) return true;
                }
                m[nums[i]].push_back(i);
            }
            return false;
        }
    };
    ```

- Occurence of number count
    - Map it in different dimension, the 32 bit pattern addition for all numbers, then count occurence.
- Access a vector by `&` to get reference
- Can substitute map with `vector<int>freq2(1001,0)`
    - In case the input space is less.
    - Efiicien as `nlogn` avoided but memory additional.
- Power of two invalid for negative number.
- isPowerOfTwo `!(n & n-1)`
    ```c++
        if( n > 1 )
            while( n % 3 == 0 ) n /= 3;
        return n == 1;
    ```
- In case of alternating bit

    ```c++
    // My approach was totally bit based to shift and check
    // bulitin_clz will count leading zero
    // builtin_ctz will last zero
    // builtingpopcount qill count one with more speed

    bool hasAlternatingBits(int n) {
        int curr = n & 1;
        n >>= 1;
        while( n > 0 ) {
            if ( curr == ( n & 1) ) return false;
            curr = n&1;
            n >>= 1;
        }
        return true;
    }
    ```
- Nth element
    ```c++
    nth_element(nums.begin(), 
    nums.begin() + nums.size()/2, 
    nums.end());
    ```

- Efficient Power
    ```c++
    double myPow(double x, int n) {
            bool isNeg = n < 0;
            n = abs(n);
            if ( n == 0 ) return 1;
            if ( n == 1 ) return 1;
            double result = 1;
            while(n) {
                if (n % 2) {
                    result *= x;
                    n--;
                } else {
                    x *= x;
                    n = n >> 1; 
                }
            }
            if (isNeg) result = 1 / result;        
            return result;
        }
    ```

- Check number of set bits

    ```c++
    for ( count = 0; number; count++) number &= number - 1;
    ```

- Next Permutation
    - We only change the position of a "digit" when everything to the right is in descending order
    - Find the next largest digit and put it in front and then put the remaining digits in ascending order

- Priority Queue in case of top k elements

- `std::sort()` vs `std::partial_sort()`: Some of you might think that why are we using `std::partial_sort`, in place we can use `std::sort()` for the limited range, but remember, if we use `std::sort` with a partial range, then only elements within that range will be considered for sorting, while all other elements outside the range will not be considered for this purpose, whereas with `std::partial_sort()`, all the elements will be considered for sorting.
#Finish
https://www.youtube.com/watch?v=-0tO3Eni2uo
`sort: O(N log(N))`
`partial_sort: "approximately" O(N log(M))`

    ```c++
    // pair usage
    vector<pair<int,int>> numWithIndex(size(nums));
        for(int i = 0; i < size(nums); i++) numWithIndex[i] = {nums[i], i};
        
        partial_sort(begin(nums), 
                    begin(nums) + k, 
                     end(nums),
                        [](auto &left, auto &right)) {
            return left.first > right.second;
        });
    ```

- `string.substr(n)` create substr after n
- `string.substr(0, n)` create substr upto n
- `*next(s.begin(), n)` or `vector<int>(bag.begin(), bag.end()).at(1)` in `set` to access nth element in sorted order

- In case of `bst` inorder gives sorted, in case of `binary tree` preorder gives

- Count number of 1
    ```c++
    a = a&(a-1);
    ++cnt;

    sort(arr.begin(), arr.end(), [this](int &a, int &b) {
        int vala = count(a), valb = count(b);
        return vala <  valb || vala == valb && a < b;
    });
    ```

- Initialize every variable
    - https://leetcode.com/problems/largest-number-at-least-twice-of-others/
    - Causes prblem if dont

-  Sort Array By Parity
    - Parity means all numbers present is odd / even

- Try using
    ```c++
    for (auto& it: B) {
        // Do stuff
        cout << it.first;
    }
    ```

- Iterating unordered map
    ```c++
    for(auto& word: bucket) if(word.second == 1001) result++;
    ```

- Declare variables close to its usage
    - It optimizes

    ```c++
    void t() {
        int var; 
        while(1) var = 4;
    }

    void t() {
        while(1) int var = 4;
    }
    
    t():
        push    rbp
        mov     rbp, rsp
    .L2:
        mov     DWORD PTR [rbp-4], 4
        jmp     .L2
    ```
- use `(nums[even] & 1)` this operation 


- priority queue
    - You cant iterate over it
    - Can copy and extract copy

    ```c++
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int, vector<int>> maxh;
    priority_queue<int, vector<int>, decltype(comp)> custom(comp);
    ```

- https://leetcode.com/problems/combinations/submissions
    - When using problem like this, always use index + 1 for next step when there is array involved
    - When a range of numbers, always use for loop for less stack allocation

- `nth_element` takeaway

- lambda recursion
    ```c++
    class Solution {
    public:
        int findGCD(vector<int>& nums) {
            int minS = INT_MAX;
            int maxS = INT_MIN;
            
            for(auto s: nums) {
                maxS = max(s, maxS);
                minS = min(s, minS);
            }
            
            function<int (int, int)> gcd;
            gcd = [&gcd](int a, int b) {
                if ( b == 0 ) return a;
                return (a > b) ? gcd(b, a - b): gcd(a, b - a);
            };
            
            return gcd(minS, maxS);
        }
    };
    ```

- Use `n = size(vec)` at the beginning, as `size()` is unsigned it creates prblem if the bound ``size() - biggner` used in loop.

- Mountain problem prefix, suffix
- Interval problem sort by first
- Collision stack
- binary search always (left <= right)
- No Dummy from now on
- `partial_sum(a, a + 5, b);` to calculate prefix sum
- `Treemap` is sorted map


- [Bit manipulation](https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently)


- For binary search
- if `left = mid + 1` and `right = mid - 1` is used then (left < right) else (left < right)

```c++
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};
```

- Reverse List
```c++
ListNode* reverseList(ListNode* head) {
    ListNode *cur = head, *prev = nullptr;
    while (cur != nullptr) {
        swap(cur->next, prev);
        swap(prev, cur);
    }
    return prev;
}

ListNode* removeNodes(ListNode* head) {
    head = reverseList(head);
    for (auto p = head; p != nullptr && p->next != nullptr; ) {
        if (p->val > p->next->val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return reverseList(head);
}

ListNode* removeNodes(ListNode* head) {
    ListNode tmp(INT_MAX);
    vector<ListNode*> st{ &tmp };
    for (auto p = head; p != nullptr; p = p->next) {
        while (st.back()->val < p->val) 
            st.pop_back();
        st.back()->next = p;
        st.push_back(p);
    }
    return tmp.next;
}
```

- `nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])`
- If in this pattern apply two sum


- Monotone Stack
- https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step


- In case of set you can use bitmask
```c++
class Solution {
public:
    int countPoints(string rings, int res = 0) {
        vector<unordered_set<char>> rods(10);
        for (int i = 0; i < rings.size(); i += 2) {
            auto pos = rings[i + 1] - '0';
            auto val = rings[i];
            rods[pos].insert(val);
        }
        for (auto val: rods) if (val.size() == 3) res++;
        return res;
    }
};
```

- To find a number between a range that satisfies something
    - Binary search