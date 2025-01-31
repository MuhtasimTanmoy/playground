// https://leetcode.com/problems/minimum-array-end/discuss/5081947/JavaC%2B%2BPython-Bits-Manipulation

class Solution {
public:
    long long minEnd(int n, int x) {
        long long a = x;
        while (--n) a = (a + 1) | x;
        return a;
    }
};