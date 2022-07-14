class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;
        auto n = size(matchsticks); auto side = sum / 4; auto dp = vector<int>(1<<n, -1);
        dp[0] = 0;
        for(int i = 0; i < (1<<n); i++) {
            if (dp[i] == -1) continue;
            for(int j = 0; j < n; j++)
                if ( !(i & (1<<j)) && dp[i] + matchsticks[j] <= side)
                    dp[i | (1<<j)] = (dp[i] + matchsticks[j]) % side;
        }
        return dp.back() == 0;
    }
};