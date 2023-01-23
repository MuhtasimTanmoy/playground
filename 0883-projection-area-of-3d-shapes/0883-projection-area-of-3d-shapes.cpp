class Solution {
public:
    int projectionArea(vector<vector<int>>& grid, int down = 0, int row = 0, int col = 0) {
        
        for (int i = 0; i < grid.size(); i++)
            row += *max_element(grid[i].begin(), grid[i].end());
        
        for (int i = 0; i < grid.size(); i++) {
            int maxElem = 0;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[j][i]) down++;
                maxElem = max(maxElem, grid[j][i]);
            }
            col += maxElem;
        }
        
        return down + row + col; 
    }
};