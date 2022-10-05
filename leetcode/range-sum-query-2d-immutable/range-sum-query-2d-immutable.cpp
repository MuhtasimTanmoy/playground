class NumMatrix {
    vector<vector<int>> sum;
    int row, col;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        sum.resize(row, vector<int>(col, 0));
        
        sum[0][0] = matrix[0][0];
        
        for (int i = 1; i < row; ++i)
            sum[i][0] += sum[i-1][0] + matrix[i][0];
        
        for (int j = 1; j < col; ++j)
            sum[0][j] += sum[0][j-1] + matrix[0][j];
        
        for (int i = 1; i < row; ++i)
            for (int j = 1; j < col; ++j)
                sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = col1 ? sum[row2][col1-1] : 0;
        int top = row1 ? sum[row1-1][col2] : 0;
        int dig = row1 && col1 ? sum[row1-1][col1-1] : 0;
        return sum[row2][col2] - left - top + dig;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */