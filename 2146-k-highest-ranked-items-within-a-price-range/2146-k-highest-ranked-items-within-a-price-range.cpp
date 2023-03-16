class Solution {
public:
    int dir[5] = {0, -1, 0, 1, 0};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, 
                                            vector<int>& pricing, 
                                            vector<int>& start, int k) {
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
        vector<vector<int>> res;
        pq.push({0, grid[start[0]][start[1]], start[0], start[1]});
        grid[start[0]][start[1]] = 0;
        while (pq.size() && res.size() < k) {
            auto [dist, price, x, y] = pq.top(); pq.pop();
            if (price >= pricing[0] && price <= pricing[1])
                res.push_back({x, y});
            for (int d = 0; d < 4; ++d) {
                int x1 = x + dir[d], y1 = y + dir[d + 1];
                if (min(x1, y1) >= 0 && x1 < grid.size() 
                    && y1 < grid[x1].size() && grid[x1][y1] != 0) {
                    pq.push({dist + 1, grid[x1][y1], x1, y1});
                    grid[x1][y1] = 0;
                }
            }
        }
        return res;
    }
};