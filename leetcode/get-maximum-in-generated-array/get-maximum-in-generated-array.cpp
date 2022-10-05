class Solution {
public:
    int getMaximumGenerated(int n) {
        
        int dp[n + 1];
        dp[0] = 0;
        int res = 0;

        if (n) {
            dp[1] = 1;
            res = 1;
        }
        
        for ( int i = 2; i <= n; i++ ) {
            dp[i] = ( i & 1 ) ? dp[i >> 1] + dp[(i >> 1) + 1] : dp[i >> 1];
            res = max(res, dp[i]);
        }
        
        return res;
    }
};