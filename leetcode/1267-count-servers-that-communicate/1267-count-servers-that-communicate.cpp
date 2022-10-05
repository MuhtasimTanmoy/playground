class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        int r = size(grid), c = size(grid[0]);
        vector<int> col(c, 0), row(r, 0);
        
        for ( int i = 0; i < r; i ++)
            for ( int j = 0; j < c; j++)
                if (grid[i][j]) {
                    col[j]++;
                    row[i]++;
                }
        
        for ( int i = 0; i < r; i ++) 
            for ( int j = 0; j < c; j++) 
                if (grid[i][j]) if (col[j] > 1 || row[i] > 1) count++;
        
        return count;
    }
};