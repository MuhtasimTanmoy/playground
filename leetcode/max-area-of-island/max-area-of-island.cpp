class Solution {
public:
    int maxAreaOfIsland(vector< vector<int> >& grid) {

        int maxArea = 0;
        
        // In each traversal reinitiate it
        int currentlyComputingMaxArea = 0;
        
        // four direction
        
        std::function< void (int, int)> traverseMark = [&] (int x, int y) {
            
            if ( y < 0) { return; }
            if ( x < 0) { return; }
			if ( x == grid.size()) { return; }
			if ( y == grid[0].size() ) { return; }

            if (grid[x][y] == 1) {
                currentlyComputingMaxArea++;
                maxArea = max( maxArea, currentlyComputingMaxArea);
                grid[x][y] = -1;
                traverseMark(x + 1, y);
                traverseMark(x, y + 1);
                traverseMark(x - 1, y);
                traverseMark(x, y - 1);
            }
        };
                
        // Traverse
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
				// cout<< grid[i][j];
                currentlyComputingMaxArea = 0;
                traverseMark(i, j);
            }
			// cout<<endl;
        }
                
        return maxArea;
    }
};