class Solution {
public:
    int firstCompleteIndex(vector<int>& a, vector<vector<int>>& m) {
        auto col_len = m.size(), row_len = m[0].size();
        vector<pair<int, int>> mapper(a.size() + 1, {0, 0});
        for (int i = 0; i < col_len; i++)
            for (int j = 0; j < row_len; j++)
                mapper[m[i][j]] = {i, j};
        
        vector<int> row(col_len), col(row_len);
        for (auto i = 0; i < a.size(); i++) {
            auto pos = mapper[a[i]];
            if (++row[pos.first] == row_len) return i;
            if (++col[pos.second] == col_len) return i;
        }
        throw "error";
    }
};