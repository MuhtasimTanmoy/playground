class Solution {
public:
    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     auto m = grid.size() - 1, n = grid[0].size() - 1;
    //     vectot<vector<int>> v(m + 1, vector<int>(n + 1, -1));
    //     vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    //     auto is_valid = [&](int x, int y) {
    //         if (x < 0 || x > m) return false;
    //         if (y < 0 || y > n) return false;
    //         if (v[x][y]) return false;
    //         return true;
    //     };
    //     function<int(int, int, int)> go = [&](auto i, auto j, auto sum) {
    //         v[i][j] = 1;
    //         if (i == m && j == n) return sum % k == 0 ? 1: 0;
    //         int res = 0;
    //         for (auto dir: dirs) {
    //             auto to_x = i + dir.first, to_y = j + dir.second;
    //             if (is_valid(to_x, to_y))
    //                 res += go(to_x, to_y, sum + grid[to_x][to_y]);
    //         }
    //         return res;
    //     };
    //     return go(0, 0, grid[0][0]);
    // }
    int numberOfPaths(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> ra(n + 1, vector<int>(k + 1)), rb = ra;
        rb[1][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                for (int l = 0; l < k; ++l)
                    ra[j + 1][(l + g[i][j]) % k] = (ra[j][l] + rb[j + 1][l]) % 1000000007;
            swap(ra, rb);
        }
        return rb[n][0];
    }
};