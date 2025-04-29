class Solution {
    vector<vector<int>> dp;
public:
    int minCost(vector<int>& N) {
        N.push_back(0);
        auto dp = vector<vector<int>>(N.size(), vector<int>(N.size(), -1));

        function<int(int, int)> go = [&](auto pre_i, auto i) {
            if (i >= N.size()) return N[pre_i];
            if(dp[i][pre_i] != -1) return dp[i][pre_i];

            int res = INT_MAX;
            auto one = max(N[i], N[i-1]), 
                 two = max(N[i], N[pre_i]),
                 three = max(N[pre_i], N[i-1]);
                
            res = min(one + go(pre_i, i + 2), res);
            res = min(two + go(i-1, i + 2), res);
            res = min(three + go(i, i + 2), res);
            return dp[i][pre_i] = res;
        };
        return go(0, 2);
    }
};