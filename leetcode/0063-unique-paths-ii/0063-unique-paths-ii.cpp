class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size() - 1, n = g.front().size() - 1;
        if (g[0][0] || g[m][n]) return 0;
        
        vector<int> dirs = {0, 1, 0};
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        function<int(int, int)> go = [&](auto x, auto y) {
            if (x == m && y == n) return 1;
            if (dp[x][y] != -1) return dp[x][y];
            g[x][y] = 1;
            
            int res = 0;
            for (int i = 0; i < 2; i++) {
                auto to_x = x + dirs[i], to_y = y + dirs[i + 1];
                if (min(to_x, to_y) >= 0 
                    && to_x <= m 
                    && to_y <= n 
                    && g[to_x][to_y] == 0)
                        res += go(to_x, to_y);
            }
            
            g[x][y] = 0;
            return dp[x][y] = res;
        };
        
        return go(0, 0);
    }
};