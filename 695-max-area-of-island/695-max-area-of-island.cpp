class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        int currMaxArea = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        function<void(int, int)> check = [&](int i, int j) -> void {
            grid[i][j] = -1;
            currMaxArea++;
            for(auto direction: directions) {
                auto nextX = i + direction[0];
                auto nextY = j + direction[1];
                if (nextX >= 0 && nextY >= 0 
                    && nextX < size(grid) && nextY < size(grid[0])
                    && grid[nextX][nextY] == 1) 
                        check(nextX, nextY);
            }
        };
        
        for (int i = 0; i < size(grid); i++)
            for (int j = 0; j < size(grid[0]); j++) if (grid[i][j] == 1) {
                currMaxArea = 0;
                check(i, j);
                maxArea = max(currMaxArea, maxArea);
            }
        return maxArea;
    }
};