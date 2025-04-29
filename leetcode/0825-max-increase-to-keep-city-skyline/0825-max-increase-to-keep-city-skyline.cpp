class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& G) {
        int c = G.size(), r = G[0].size();
        vector<int> max_in_row, max_in_col;
        for (auto i = 0; i < c; i++) {
            int val = 0;
            for (auto j = 0; j < r; j++) val = max(val, G[i][j]);
            max_in_col.push_back(val);
        }
        for (auto i = 0; i < r; i++) {
            int val = 0;
            for (auto j = 0; j < c; j++) val = max(val, G[j][i]);
            max_in_row.push_back(val);
        }
        int res = 0;
        for (auto i = 0; i < c; i++) 
            for (auto j = 0; j < r; j++) {
                auto can_be = min(max_in_row[i], max_in_col[j]);
                res += can_be - G[i][j];
            }
        return res;
    }
};

// [3,0,8,4]
// [2,4,5,7]
// [9,2,6,3]
// [0,3,1,0]