class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> go =[&](auto x, auto y) {
            if (x == (m - 1) && y == (n - 1)) return 1;
            if (dp[x][y] != -1) return dp[x][y];
            int ways = 0;
            if (x + 1 < m) ways += go(x + 1, y);
            if (y + 1 < n) ways += go(x, y + 1);
            return dp[x][y] = ways;
        };
        return go(0, 0);
    }
};