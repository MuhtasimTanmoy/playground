class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        auto isInDiag = [&](int i, int j) -> bool {
            if (i == j) return true;
            if (n - i - 1 == j) return true;
            return false;
        };
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                if (isInDiag(i, j)) {
                    if (grid[i][j]) continue;
                    else return false;
                }
                if (grid[i][j]) return false;
            }
        return true;
    }
};