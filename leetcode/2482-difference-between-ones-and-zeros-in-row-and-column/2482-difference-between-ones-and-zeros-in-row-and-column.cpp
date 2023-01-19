class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size(),vector<int>(grid[0].size(), 0));
        vector<int> col(grid[0].size(), 0), row(grid.size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            int rowSum = 0;
            for (int j = 0; j < grid[i].size(); j++) 
                rowSum += grid[i][j], col[j] += grid[i][j];
            row[i] = rowSum;
        }
        
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[i].size(); j++) 
                res[i][j] = 2 * (row[i] + col[j] ) - grid[i].size() - grid.size();
        return res;
    }
};