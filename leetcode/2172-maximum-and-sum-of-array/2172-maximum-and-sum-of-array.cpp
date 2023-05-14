// https://leetcode.com/problems/maximum-and-sum-of-array/discuss/1766824/JavaC%2B%2BPython-DP-Solution
class Solution {
public:
     int maximumANDSum(vector<int>& A, int ns) {
        int mask = pow(3, ns) - 1;
        vector<int> memo(mask + 1, 0);

        function<int(int, int)> dp =
        [&](auto i, auto mask) {
            int& res = memo[mask];
            if (res > 0) return res;
            if (i < 0) return 0;
            for (int slot = 1, bit = 1; slot <= ns; ++slot, bit *= 3)
                if (mask / bit % 3 > 0)
                    res = max(res, (A[i] & slot) + dp(i - 1, mask - bit));
            return res;
        };

        return dp(A.size() - 1, mask);
    }
};