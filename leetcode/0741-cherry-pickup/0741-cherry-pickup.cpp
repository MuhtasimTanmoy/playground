// Wrong answer
/*
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        auto n = grid.size(), m = grid[0].size();
        auto is_valid = [&](int i, int j) {
            if (i < 0 || i == n) return false;
            if (j < 0 || j == m) return false;
            if (grid[i][j] == -1) return false;
            return true;
        };
        bool reached = false;
        function<int(int, int)> go = [&](auto i, auto j) -> int {
            if (i + 1 == n && j + 1 == m) {
                reached = true;
                auto is_taken = grid[i][j] == 1;
                grid[i][j] = 0;
                return is_taken;
            }
            
            auto is_taken = grid[i][j] == 1;
            grid[i][j] = 0;
            
            auto right = is_valid(i, j + 1) ? go(i, j + 1): 0;
            auto down = is_valid(i + 1, j) ? go(i + 1, j): 0;
            return is_taken + right + down;
        };
        auto res = go(0, 0);
        return reached ? res: 0;
    }
};
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        int P_LEN = N + N - 1;
        vector<vector<int> > dp = vector<vector<int>>(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];
        
        for (int p = 2; p <= P_LEN; p++) {
            for (int x1 = N - 1; x1 >= 0; x1--) {
                for (int x2 = x1; x2 >= 0; x2--) {
                    int y1 = p - 1 - x1;
                    int y2 = p - 1 - x2;
                    if (y1 < 0 || y2 < 0 || y1 >= N || y2 >= N) continue;
                    
                    if (grid[y1][x1] < 0 || grid[y2][x2] < 0) {
                        dp[x1][x2] = -1;
                        continue;
                    }
                    
                    int best = -1, delta = grid[y1][x1];
                    if (x1 != x2)
                        delta += grid[y2][x2];
                    if (x1 > 0 && x2 > 0 && dp[x1 - 1][x2 - 1] >= 0)
                        best = max(best, dp[x1 - 1][x2 - 1] + delta);
                    if (x1 > 0 && y2 > 0 && dp[x1 - 1][x2] >= 0)
                        best = max(best, dp[x1 - 1][x2] + delta);
                    if (y1 > 0 && x2 > 0 && dp[x1][x2 - 1] >= 0)
                        best = max(best, dp[x1][x2 - 1] + delta);
                    if (y1 > 0 && y2 > 0 && dp[x1][x2] >= 0)
                        best = max(best, dp[x1][x2] + delta);
                    dp[x1][x2] = best;
                }
            }
        }
        return dp[N - 1][N - 1] < 0 ? 0 : dp[N - 1][N - 1];
    }
};