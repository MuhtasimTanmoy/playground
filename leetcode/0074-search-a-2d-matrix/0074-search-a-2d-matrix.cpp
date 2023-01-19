class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target, 
                      int x = 0, int y = 0) {
        auto isValid = [&](int x, int y) {
            if (x < 0 || x == matrix.size()) return false;
            if (y < 0 || y == matrix[0].size()) return false;
            return true;
        };
        
        while (isValid(x, y)) {
            if (matrix[x][y] == target) return true;
            if (x < matrix.size() - 1) 
                if (matrix[x + 1][y] <= target) {
                    x++; continue;
                }
            y++;
        }
        
        return false;
    }
};