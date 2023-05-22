class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e5 + 1));
        priority_queue<tuple<int, int, int>, 
                        vector<tuple<int, int, int>>, 
                        greater<tuple<int, int, int>>> pq;
        
        pq.push({grid[0][0], 0, 0});
        int dirs[4][2] = {{0, 1},{-1, 0},{1, 0},{0, -1}};
        while (pq.size()) {
            auto [c, i, j] = pq.top();
            pq.pop();
            
            if (i == n - 1 && j == m - 1) return c;
            for (auto &d: dirs) {
                int x = d[0] + i, y = d[1] + j;
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (dp[x][y] > grid[x][y] + c) 
                    dp[x][y] = grid[x][y] + c,
                    pq.push({grid[x][y] + c, x, y});
            }
        }
        
        return -1;
    }
};