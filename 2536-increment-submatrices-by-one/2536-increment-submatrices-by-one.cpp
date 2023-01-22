class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));
        for (auto query: queries) {
            auto x = query[0], y = query[1], toX = query[2], toY = query[3];
            res[x][y]++, res[x][toY + 1]--, res[toX + 1][y]--, res[toX + 1][toY + 1]++;
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                if (i) res[i][j] += res[i-1][j];
                if (j) res[i][j] += res[i][j-1];
                if (i && j) res[i][j] -= res[i-1][j-1];
            }
        res.pop_back();
        for (auto &row: res) row.pop_back();
        return res;
    }
};