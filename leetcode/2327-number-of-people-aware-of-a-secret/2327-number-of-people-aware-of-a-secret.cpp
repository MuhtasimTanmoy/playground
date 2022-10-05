class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1);
        for (auto i = 1; i <= forget; ++i) dp[i] = 1;
        for (int i = 1; i < n; i++)
        for (int j = i + delay; j <= min(n, i + forget - 1); j++)
            dp[j] = (dp[j] + dp[i]) % int(1e9 + 7);
        return dp[n];
    }
};