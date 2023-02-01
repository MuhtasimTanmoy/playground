- [Contest 1312](https://codeforces.com/contest/1312)
  - A
    - Different polygons with same center with different vertices(n, m) should have `( n % m )` relation
  - B
    - `sort(a, a+n, greater<int>())`
  - C 
    - `0 0 0 0 0` -> `1 90 9^3 0` to get there use base `9` as many times as possible with no intersect
    - 9 ( 1 + 9) in case of 90
  - D
    - Consider adjacent to to mix up

### https://codeforces.com/contest/1299/problem/A 
> Complete
- https://codeforces.com/blog/entry/73763
- pattern prefix

- suffix
- middle
- https://codeforces.com/contest/1299/submission/70745511

### https://codeforces.com/contest/455/problem/A
> try
> number & count
> sort

### https://codeforces.com/contest/455/problem/B

### https://codeforces.com/contest/1326/problem/A
> large number bt cant be divisible by own digits

> https://www.geeksforgeeks.org/check-if-a-large-number-is-divisible-by-2-3-and-5-or-not/?ref=rp

> A number is divisible by 9 if sum of its digits is divisible by 9.
> A number is divisible by 3 if sum of its digits is divisible by 3.
> 233333333 > all digits not divisible by digits

A number is divisible by 6 it's divisible by 2 and 3. 
a)  A number is divisible by 2 if its last digit is divisible by 2.
b)  A number is divisible by 3 if sum of digits is divisible by 3.

> A number is divisible by 8 if number formed by last three digits of it is divisible by 8.

> A number is divisible by 4 if number formed by last two digits of it is divisible by 4.

> Input : 8955795758
Output : Divisible by 7
       Explanation:
       We express the number in terms of triplets 
       of digits as follows.
                (008)(955)(795)(758)
       Now, 758- 795 + 955 - 8 = 910, which is 
       divisible by 7

Input : 100000000000
Output : Not Divisible by 7
       Explanation:
       We express the number in terms of triplets 
       of digits as follows.
                (100)(000)(000)(000)
       Now, 000- 000 + 000 - 100 = -100, which is 
       not divisible by 7

# Collatz Conjecture or 3N+1 conjecture
 The problem is known as Collatz Conjecture or 3N+1 conjecture and it states that every positive integral number will ultimately lead to 1 if the operations that was described in the problem was performed.