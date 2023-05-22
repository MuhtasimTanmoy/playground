class Solution {
public:
//     int maxMoves(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<pair<int, int>> dirs = {{-1, 1}, {0, 1}, {1, 1}};
//         vector<vector<bool>> seen(m, vector<bool>(n, false));

//         auto is_valid = [&](int x, int y) {
//             if (x < 0 || x >= m) return false;
//             if (y < 0 || y >= n) return false;
//             return seen[x][y] == false;
//         };
        
//         int res = 0;
//         for (int i = 0; i < m; i++) {
//             int depth = 0;
//             vector<pair<int, int>> stk; stk.emplace_back(i, 0);
//             while (stk.size()) {
//                 auto n = stk.size();
//                 vector<pair<int, int>> temp;
//                 while (n--) {
//                     auto [x, y] = stk.back(); seen[x][y] = true;
//                     auto curr = grid[x][y];
//                     stk.pop_back();
//                     for (auto [_x, _y]: dirs) {
//                         auto to_x = x + _x, to_y = y + _y;
//                         if (is_valid(to_x, to_y) && curr < grid[to_x][to_y])
//                             temp.emplace_back(to_x, to_y);
//                     }
//                 }
//                 swap(stk, temp);
//                 res = max(res, depth++);
//             }
//         }
//         return res;
//     }
    
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 1}, {-1, 1}};
        vector<vector<int>> cache(m, vector<int>(n, -1));

        function<int(int, int)> dp = [&](int i, int j) {
            if (cache[i][j] != -1) return cache[i][j];
            int ans = 0;
            for (auto [x, y] : dirs) {
                int ni = i + x, nj = j + y;
                if (ni >= 0 && ni < m && nj < n && grid[i][j] < grid[ni][nj])
                    ans = max(ans, 1 + dp(ni, nj));
            }
            return cache[i][j] = ans;
        };

        int res = 0;
        for (int i = 0; i < m; i++)
            res = max(res, dp(i, 0));
        return res;
    }
};