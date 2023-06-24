class Solution {
public:
    int minimumDeleteSum(string l, string r) {
        vector<vector<int>> dp(l.size(), vector<int>(r.size(), -1));
        function<int(int, int)> go = [&](auto li, auto ri) {
            if (li == l.size() || ri == r.size()) return 0;
            if (dp[li][ri] != -1) return dp[li][ri];
            if (l[li] == r[ri])
                return dp[li][ri] = l[li] + go(li + 1, ri + 1);
            else 
                return dp[li][ri] = max(go(li, ri + 1), go(li + 1, ri));
        };
        auto lcs =  go(0, 0);
        auto l_sum = accumulate(l.begin(), l.end(), 0),
             r_sum = accumulate(r.begin(), r.end(), 0);
        return l_sum + r_sum - 2 * lcs;
    }
};