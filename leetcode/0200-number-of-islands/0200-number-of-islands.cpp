class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        function<void(int, int)> traverse = [&](int x, int y) {
            if (x < 0 || x >= grid.size() 
                || y < 0 || y >= grid[0].size()) return;
            
            if (grid[x][y] != '1') return;
            grid[x][y] = '0';
            vector<vector<int>> directions = {{x, y + 1}, 
                                              {x + 1, y}, 
                                              {x - 1, y}, 
                                              {x, y - 1}};
            for (auto direction: directions) 
                traverse(direction[0], direction[1]);
        };
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1') 
                    numIslands++,
                    traverse(i, j);        
        return numIslands;
    }
};