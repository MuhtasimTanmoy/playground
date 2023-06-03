class Solution {
    int dp[102][102] = {};
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        function<int(int, int)> go = [&](auto l, auto r) {
            if (r - l <= 1) return 0;
            if (dp[l][r]) return dp[l][r];
            
            int res = INT_MAX;
            for (int i = l + 1; i < r; i++)
                res = min(res, (cuts[r] - cuts[l]) + go(l, i) + go(i, r));
            return dp[l][r] = res;
        };
        return go(0, cuts.size() - 1);
    }
};