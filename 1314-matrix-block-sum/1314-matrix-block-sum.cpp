class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int sum = 0;
                for (int r = max(0, i - k); r < min(n, i + k + 1); r++)
                    for (int c = max(0, j - k); c < min(m, j + k + 1); c++) 
                        sum += mat[r][c];
                res[i][j] = sum;
            }
        return res;         
    }
};