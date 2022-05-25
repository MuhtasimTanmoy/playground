class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> elems;
        int rem = grid[0][0] % x;
        
        bool isDiv = true;
        for(int i = 0; i < size(grid) && isDiv; i++) {
            for(int j = 0; j < size(grid[0]) && isDiv; j++) {
                if (grid[i][j] % x != rem) isDiv = false;
                elems.push_back(grid[i][j]);
            }
        }
        
        if (!isDiv) return -1;
        
        int mid = size(elems) >> 1;
        nth_element(elems.begin(), elems.begin() + mid, elems.end() );
        
        int res = 0;
        for(int i = 0; i < size(elems); i++) {
            res += ( abs(elems[i] - elems[mid]) / x );
        }
        return res;
        
    }
};