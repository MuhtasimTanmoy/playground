class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> cache(100, vector<int>(100, -1));
        if (matrix.empty()) return 0;
        
        auto isValid = [&](int x, int y) {
            if (x < 0 || y < 0) return false;
            if (x >= matrix.size() || y >= matrix[0].size()) return false;
            return true;
        };
        
        function<int(int, int)> go = [&](auto x, auto y) {
            int res = INT_MAX;
            if (cache[x][y] != -1) return cache[x][y];
            
            auto dirs = {-1, 0, 1};
            for (auto dir: dirs) {
                if (isValid(x + 1, y + dir) == false) continue;
                auto score = matrix[x][y] + go(x + 1, y + dir);
                res = min(res, score);
            }
            return cache[x][y] = res == INT_MAX? matrix[x][y]: res;
        };
        
        int res = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++) {
            auto minPathSum = go(0, i);
            res = min(res, minPathSum);
        }
        return res;
    }
};