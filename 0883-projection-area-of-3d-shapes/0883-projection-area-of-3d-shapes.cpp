class Solution {
public:
    int projectionArea(vector<vector<int>>& grid, int res = 0) {
        for (int i = 0; i < grid.size(); i++) {
            int maxCol = 0, maxRow = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[j][i]) res++;
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
            }
            res += maxCol + maxRow;
        }
        return res; 
    }
};