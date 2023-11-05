class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res = {{1}};
        for (int i = 1; i < n; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                auto l = j ? res.back()[j - 1]: 0, r = j < i ? res.back()[j]: 0;
                row.push_back(l + r);
            }
            res.push_back(row);
        }
        return res;
    }
};