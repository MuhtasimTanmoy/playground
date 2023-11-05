class Solution {
public:
    // vector<int> countBits(int n) {
    //     vector<int> res;
    //     for (int i = 0; i <= n; i++) res.push_back(__builtin_popcount(i));
    //     return res;
    // }
     vector<int> countBits(int n) {
        vector<int> res, dp(n + 1);
        for (int i = 0; i <= n; i++) 
            dp[i] = dp[i >> 1] + (i & 1),
            res.push_back(dp[i]);
        return res;
    }
};