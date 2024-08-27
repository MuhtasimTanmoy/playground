class Solution {
    int dp[2001][4000];
public:
    int maxTotalReward(vector<int>& r) {
        memset(dp, -1, sizeof(dp));
        auto one = unordered_set<int>(r.begin(), r.end());
        vector<int> rewards(one.begin(), one.end());
        sort(rewards.begin(), rewards.end());
        int n = rewards.size();
        
        function<int(int, int)> go = [&](auto i, auto curr) {
            if (i == n) return 0;
            
            if (dp[i][curr] != -1) return dp[i][curr];
            auto res = go(i + 1, curr);
            for (auto now = i; now < n; now++)
                if (rewards[now] > curr) {
                    res = max(res, rewards[now] + go(now + 1, rewards[now] + curr));
                    break;
                }
            return dp[i][curr] = res;        
        };
        return go(0, 0);
    }
};