class Solution {
public:
    
    void mark(vector<vector<int>>& grid, int i, int j) {

        if (!( i >= 0 && i < size(grid) )) { return; }
        if (!( j >= 0 && j < size(grid[0]) )) { return; }
        
        if (grid[i][j] == 0 ) { return; }
        grid[i][j] = 0;
            
        mark(grid, i+1, j);
        mark(grid, i, j+1);
        mark(grid, i-1, j);
        mark(grid, i, j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        for(int i = 0; i < size(grid); i++ ) {
            for(int j = 0; j < size(grid[0]); j++ ) {
                if (i == 0 
                    || j == 0 
                    || i == size(grid) - 1 
                    || j == size(grid[0]) - 1) {
                    
                    cout<<"marking"<<i<<" "<<j<<endl;
                    if (grid[i][j] == 1) mark(grid, i, j);
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < size(grid); i++ ) {
            for(int j = 0; j < size(grid[0]); j++ ) {
                if (grid[i][j] == 1) count++;
            }
        }
        
        return count;
    }
};