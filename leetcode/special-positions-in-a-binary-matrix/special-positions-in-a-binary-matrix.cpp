class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), res = 0;
        vector<int> rcnt(row, 0), ccnt(col, 0);
        
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) {
                if (mat[i][j]) {
                    ++rcnt[i];
                    ++ccnt[j];
                }
            }
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (mat[i][j] && rcnt[i] == 1 && ccnt[j] == 1) 
                    ++res;
        return res;
    }
};