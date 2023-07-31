class Solution {
public:
//     bool isPossibleToCutPath(vector<vector<int>>& grid) {
//         int tx = grid[0].size() - 1, ty = grid.size() - 1;
//         auto is_valid = [&](auto i, auto j) {
//             if (i > ty || j > tx || grid[i][j] == 0) return false;
//             return true;
//         };
//         function<bool(int, int)> traverse = [&](auto i, auto j) {
//             if (is_valid(i, j) == false) return false;
//             if (i == ty && j == tx) return true;
            
//             if (i || j) grid[i][j] = 0;
//             auto l = traverse(i, j + 1), r = traverse(i + 1, j);
//             return l || r;
//         };
//         return traverse(0, 0) && !traverse(0, 0);
//     }
    
    bool dfs(vector<vector<int>>& g, int i, int j) {
        int m = g.size(), n = g[0].size();
        if (i == m || j == n || g[i][j] == 0)
            return false;
        if (i == m - 1 && j == n - 1)
            return true;
        if (i != 0 || j != 0)
            g[i][j] = 0;
        return dfs(g, i, j + 1) || dfs(g, i + 1, j);
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& g) {
        return !(dfs(g, 0, 0) && dfs(g, 0, 0));
    }
};