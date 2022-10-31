/*
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
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) 
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] != (matrix[i-1][j-1]))
                    return false;
        return true;
    }
};