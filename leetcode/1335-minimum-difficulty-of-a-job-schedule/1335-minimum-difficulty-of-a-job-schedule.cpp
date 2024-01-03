class Solution {
public:
   int minDifficulty(vector<int>& A, int D) {
        int n = A.size(), inf = 1e9, maxd;
        if (n < D) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) 
            for (int i = 0; i <= n - d; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) 
                    maxd = max(maxd, A[j]),
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
            }
        return dp[0];
    }
};