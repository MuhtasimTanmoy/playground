class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        auto maxX = size(matrix[0]), maxY = size(matrix);
        
        for(int i = 0; i < size(matrix[0]); i++) {
            auto firstItem = matrix[0][i];
            int x = 0, y = i;
            while (x < maxY && y < maxX) if (matrix[x++][y++] != firstItem) return false;
        }
        
        for(int i = 1; i < size(matrix); i++) {
            auto firstItem = matrix[i][0];
            int x = i, y = 0;
            while (x < maxY && y < maxX) if (matrix[x++][y++] != firstItem) return false;
        }
        
        return true;
    }
};