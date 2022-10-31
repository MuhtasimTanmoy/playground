class Solution {
public:
    int commonFactors(int a, int b) {
        int res = 1;
        for (int n = 2; n <= gcd(a, b); ++n)
            res += a % n == 0 && b % n == 0;
        return res;
    }
};