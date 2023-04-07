class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
        
        
        function<void (int, int)> markDead = [&] (int x, int y) {
            grid[x][y] = 1;
            for (auto direction: directions) {
                int nx = x + direction.first;
                int ny = y + direction.second;
                if (nx < 0 
                    || ny < 0 
                    || nx >= grid.size() 
                    || ny >= grid[0].size() 
                    || grid[nx][ny]) continue;
                markDead(nx, ny);
            }
        };
        
        function<void (int, int)> traverseMark = [&] (int x, int y) {
            grid[x][y] = 1;
            for (auto direction: directions) {
                int nx = x + direction.first;
                int ny = y + direction.second;
                if (nx < 0 
                    || ny < 0 
                    || nx >= grid.size() 
                    || ny >= grid[0].size() 
                    || grid[nx][ny]) continue;
                traverseMark(nx, ny);
            }
        };
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if (i == 0 
                    || j == 0 
                    || i == grid.size() - 1 
                    || j == grid[0].size() - 1) {
                    if (!grid[i][j]) markDead(i, j);
                }
        
         for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++) 
                if (!grid[i][j]) {
                    count++;
                    traverseMark(i, j);
                }
        
        return count;
    }
};