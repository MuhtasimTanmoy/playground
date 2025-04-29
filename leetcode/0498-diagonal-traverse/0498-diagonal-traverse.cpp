class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<pair<int, int>> idx;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
                idx.push_back({i, j});
        
        sort(idx.begin(), idx.end(), [](const auto l, const auto r) {
            auto l_sum = l.first + l.second, r_sum = r.first + r.second;
            if (l_sum == r_sum)
                return l_sum & 1 ? l.first < r.first : l.first > r.first;
            return l_sum < r_sum;
        });
        
        vector<int> res;
        for (auto p: idx) res.push_back(mat[p.first][p.second]);
        return res;
    }
};