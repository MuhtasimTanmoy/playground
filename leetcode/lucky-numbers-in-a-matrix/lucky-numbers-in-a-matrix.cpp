class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int minIndexInRow = 0;
        int minNum = INT_MAX;
        vector<int> result;
        
        for( int i = 0; i < size(matrix); i++ ) {
            for(int j = 0; j <  size(matrix[0]); j++ ) {
                if (matrix[i][j] <= minNum) {
                    minIndexInRow = j;
                    minNum = matrix[i][j];
                }
            }
            
            bool allSmall = true;
            for( int i = 0; i < size(matrix); i++ )
                if (matrix[i][minIndexInRow] > minNum) allSmall = false;
            
            if (allSmall) result.push_back(minNum);
            minNum = INT_MAX;
        }
        
        return result;
    }
};