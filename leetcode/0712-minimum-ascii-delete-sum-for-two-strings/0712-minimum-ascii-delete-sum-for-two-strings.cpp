class Solution {
    int dp[1000][1000];
public:
    int minimumDeleteSum(string l, string r) {
        
        function<int(int, int)> go = [&](auto i, auto j) {
            if (i == l.size() || j == r.size()) return 0;
            if (dp[i][j]) return dp[i][j];
            
            if (l[i] == r[j])
                return dp[i][j] = l[i] + go(i + 1, j + 1);
            else {
                auto one = go(i + 1, j), two = go(i, j + 1);
                return dp[i][j] = max(one, two);
            }
        };
        
        auto get_sum = [](string& s) {
            int res = 0;
            for (auto c: s) res += c;
            return res;
        };
        
        auto match = go(0, 0);
        auto l_sum = get_sum(l), r_sum = get_sum(r);
        return l_sum + r_sum - 2 * match;
    }
};