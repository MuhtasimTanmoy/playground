- [Programming Camp](https://www.youtube.com/channel/UCN_pqF_Y6IObpxapaQPHWZg)

- Applicable in all places
- `lightOJ` and `codeforces`
- Reserach oriented more open ended
- Engineering problems are open ended
    - Sub problems that is already known

- Solve quality problems instead of quantity, hard problems
    - Check list of problems u haven't solved, cant solve
    - Make list of those, scan complete those
    - Raise the bar
    - To improve accuracy solve easy problems lots
    - Errichito shows problem approach
    - Keep your appraoch his approach together, identify the changes
    - See solution, batch transfer learning

- [Greedy and Searching: BAPS - BACS Online Programming Camp, 2020](https://youtu.be/IKDtlUMW7F4?list=PLWtSipmftM8qbtfj2WkoQ7Z9ZrhCl6rPz)
    - Greedy
        - To immediately take best valued decision, not exploring all possible case, local maximization
        - To explore all case DP
        - In case of meeting scheduling sort by last end time, other factors, less no of conflict, start time, duration
            - When we want to attend as much meeting as possible
        - In case want to attend all with less conference room
        - `DSU` Disjoint Set Union 
            - To solve task with deadline

    - Sliding Window
        - O(n^2) to o(n) conversion using previously calculated steps

    - Two pointer method
        - In this method, naive approach is generate all possible sub array and check for condition
        - `Given string s find longest substring of S without repeating character`
        - `Hippo cost calculate`
            - Shared height to be less than required height
        - `Maximum subsegment sum`
            - Generating subarray will be `0(n^2)`
            - Keeping a cumulative sum, substracting only the least value in left should work
        - `Minimum subarray sum`
            - Keeping a cumulative sum, substracting only the most value in left should work
            - Or, making the cumulative sum array reverse sign
        - `Find maximum submatrix sum`
            - Naive: Generate all possble sub matrix
            - Can be optmized by `O(n^4)` to `O(n^3)` 
            - Kadane algorithm
        - For each K segments multiple elements
            - `(N - K + 1) logk` from multiset can be improved to `(N - K + 1)` with deque
            - Keeping only decreasing element in `deque`

    - Binary Search
        - Prefix of true, suffix of false or vice versa
        - `Rotate sorted array`, compare with last element
        - `Max in a hill`

    - Search + Greedy
        - Solve reverse problem
        - Convert it to a yes/no problem
        - `Allocate N task to k workers with t time each ascending, minimize weight`
        - `Meet in the middle`

    - Use greedy or DP
        - If greedy handles all cases, else DP


            

- [Data Structure](https://youtu.be/0v--9nEFfAM)
    - `Subarray Minimum * Subarray Length` maximization
        - Maintain increasing stack for left and right direction
        - Addition of those
    - Find largest possible sub rectangle containing only zero
        - Maintain increasing stack for left and right direction
        - Addition of those
    - Sparse Table
        - Used in skipping hop
    - Suffix Array






            



            








- [Data Structure 2](https://youtu.be/0v--9nEFfAM?list=PLWtSipmftM8qbtfj2WkoQ7Z9ZrhCl6rPz)
    - Segment Tree
        - Range minimum. Walking on segment tree, for a range if left satisfies a query then go right looking for appropiate point.
        - Find max subsequence length from valid bracket sequence.
        - Range update `(l, r, +x)` and sum query
            - Lazy propagation
    - More range query DS - SQRT Decomposition. MO’s Algorithm
    - Eulers tour
        - Running segment queries on tree
        - Running query on tree
        - In case of subtree works fine, in case of distance between `u->v`
    - HLD



            




            




            




            

- [Data Structure Advanced](https://youtu.be/94E2ztsDdyI?list=PLWtSipmftM8qmo4ysAvS-aI4nc9nLM-uv)
    - Square Root Decomposition
        - Heavy Light Tree
        - ## TODO




            




            




            




            

- [String Algorithm](https://youtu.be/zbV0IRWBNvU)
    - Query presence of string in an array
        - Fermets little theorem to compute hash for substring
        - Rabin Karp
    - Given two tree check if identical
        - https://www.geeksforgeeks.org/queries-to-check-if-string-b-exists-as-substring-in-string-a
        - ## TODO

- [String Algo ||](https://youtu.be/wH3rmwew1Cc?list=PLWtSipmftM8qbtfj2WkoQ7Z9ZrhCl6rPz)
    - Sufiix
        - Making pair 1, 2, 4 and index
        - Sparse Table
        - ## TODO

> std::string operator+ allocates a new string and copies the two operand strings every time. repeat many times and it gets expensive, O(n).

> std::string append and operator+= on the other hand, bump the capacity by 50% every time the string needs to grow. Which reduces the number of memory allocations and copy operations significantly, O(log n).




            




            




            




            




            

- [Dynamic Programming](https://youtu.be/cbgdSX2pXcQ?list=PLWtSipmftM8qbtfj2WkoQ7Z9ZrhCl6rPz)
    - Dynamic Problem used in
        - Counting problem
            - How many ways to solve a problem
        - Maximize
        - Minimize
    - Knapsack
    - Overlapping subproblem
        - state
        - return value
        - base case
        - memoization
        - transition
            - how many functions to add
    - Tiling problem
        - 2 * N Tiling
        - `return dp[n] = func(pos-1) + func(pos-2);`
        - dp with memoization is `o(n)`, `o(state) * o(func)`
        - with rotation `return dp[n] = func(pos-1) + 2 * func(pos-2);`
        - `3 * 1` & `3 * 2` with rotation `return dp[n] = func(pos-1) + func(pos-2) + 3 * func(pos-3);`
    - Given an array of N integers pick a subsequence of this array to maximize the sum of subsequence, given no consequtive take
        - Greedy if consequtive take
        - Manage state for taking an element and not taking
            - keeping `pos, prev` in param
            - for each `prev = 0` take max of taking or not taking that element
            - else dont take that element
    - Same problem, with `1 * n0 + 2 * n1 + 3 * n2` this pattern. n = 1000
        - `dp(n, m)` if n = n, m = n, time complexity n * m = n * n, worst case n ^ 2, this problem only works for 1000 not 10^5
    - Same problem, with `n0 - n1 + n2 - n3` this pattern. n = 1000
    - with alternating sign, n = 10^5
    - In case of overlapping problem, if no profit associated then greedy
        - If profit then sort by first time, o ( n * n) , as for each n state, 
        it will take n iteration to find next, to find next task greater, use `upperbound` because if task ends at 5, I start it at 6, if 
        needed to start it at 5 I would have done `lowerbound` to make o (nlogn)
    - Maximum palindromic substring
        - `return dp[n][m] = func()` 
    - Maximum palindromic subsequence
    - How many ways to construct a number with all digits
    - Permutation of a number divisible by an number
    - Digit DP
        - In a range give some count, A to B give count
        - Make that two funciton
            - `f(a, b) -> f(b) - f(a-1)`
        - NUMBER OF ZEROS FROM a to b
        - # TO BE CONTINUED
        https://leetcode.com/problems/subarray-sum-equals-k/
    




            




            




            




            

- Heavy light decomposition
- Centroid decomposition