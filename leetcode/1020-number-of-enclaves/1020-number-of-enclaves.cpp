class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int col = grid.size() - 1, row = grid[0].size() - 1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        auto is_valid = [&](int x, int y) {
            if (x < 0 || x > col) return false;
            if (y < 0 || y > row) return false;
            if (grid[x][y] == 0) return false;
            return true;
        };
        
        function<void(int, int)> mark = [&](auto x, auto y) {
            if (is_valid(x, y) == false) return;
            grid[x][y] = 0;
            for (auto dir: dirs)
                mark(x + dir.first, y + dir.second);
        };
        
        for (int i = 0; i < grid.size(); i++) 
            mark(i, 0), mark(i, row);
        for (int i = 0; i < grid[0].size(); i++) 
            mark(0, i), mark(col, i);
        
        int count = 0;
        for (auto r: grid) 
            for (auto i: r)
                count += i;
        return count;
    }
};

