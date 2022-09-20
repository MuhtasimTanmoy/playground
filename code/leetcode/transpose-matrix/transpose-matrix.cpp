class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result(size(matrix[0]), vector<int>(size(matrix), 0));
        for(int i = 0; i < size(matrix[0]); i++)
            for(int j = 0; j < size(matrix); j++)
                result[i][j] = matrix[j][i];
        return result;
    }
};