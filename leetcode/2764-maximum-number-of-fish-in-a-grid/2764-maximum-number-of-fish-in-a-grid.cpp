class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        auto is_valid = [&](int x, int y) {
            if (x < 0 || x == grid.size()) return false;
            if (y < 0 || y == grid[x].size()) return false; 
            if (!grid[x][y]) return false;
            return true;
        };
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        function<int(int, int)> go = [&](auto x, auto y) {
            if (!is_valid(x, y)) return 0;
            int calc = grid[x][y];
            grid[x][y] = 0;
            for (auto dir: dirs)
                calc += go(x + dir.first, y + dir.second);
            return calc;
        };
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j]) 
                    res = max(res, go(i, j));
        return res;
    }
};