class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        function<void(int, int, int)> traverse = [&](int x, int y, int gold) {
            if (x < 0
                || y < 0
                || x >= grid.size()
                || y >= grid[0].size()
                || !grid[x][y])
                return;
            
            auto addedGold = gold + grid[x][y];
            res = max(res, addedGold);
            
            auto cache = grid[x][y];
            grid[x][y] = 0;
            
            vector<pair<int, int>> toGo {{x + 1, y}, {x, y + 1}, {x - 1, y}, {x, y - 1}};
            for (auto dir: toGo) traverse(dir.first, dir.second, addedGold);
            grid[x][y] = cache;
        };
        
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[0].size(); j++) 
                traverse(i, j, 0);
         
        return res;
    }
};