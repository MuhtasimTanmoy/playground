class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& M) {
        unordered_map<string, int> map;
        int row = M.size(), col = M.front().size(), res = 0;
        for (int i = 0; i < row; ++i) {
            string t = "";
            for (int j = 0; j < col; ++j) t += M[i][j] == M[i][0] ? '0' : '1';
            res = max(res, ++map[t]);
        }
        return res;
    }
};