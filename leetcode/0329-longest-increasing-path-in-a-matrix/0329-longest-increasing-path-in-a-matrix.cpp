class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix, int res = 0) {
        
        vector<pair<int, int>> dirs = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};
        auto is_valid  = [&](int i, int j) {
            if (i < 0 || i == matrix.size()) return false;
            if (j < 0 || j == matrix[0].size()) return false;
            return true;
        };
        
        unordered_map<string, int> cache;
        auto gen_key = [](int i, int j) { return to_string(i) + "-" + to_string(j); };
        
        function<int(int, int)> go = [&](auto i, auto j) {
            auto key = gen_key(i, j);
            if (cache.count(key)) return cache[key];
            int local = 1;
            for (auto dir: dirs) {
                vector<int> to = {i + dir.first, j + dir.second};
                if (is_valid(to[0], to[1]))
                    if (matrix[i][j] < matrix[to[0]][to[1]])
                        local = max(local, 1 + go(to[0], to[1]));
            }
            return cache[key] = local;
        };
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++) 
                res = max(res, go(i, j));
        return res;
    }
};