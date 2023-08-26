/*

37 / 50 test cases passed.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.back().size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        auto go = [&](auto i, auto j) {
            vector<vector<bool>> mark(m, vector<bool>(n, false));
            
            vector<pair<int, int>> list {{i, j}};
            vector<int> dirs = {-1, 0, 1, 0, -1};
            int distance = 0;
            
            while (list.size()) {
                vector<pair<int, int>> temp;
                distance++;
                for (auto [x, y]: list)
                    for (int i = 1; i < dirs.size(); i++) {
                        auto to_x = x + dirs[i - 1], to_y = y + dirs[i];
                        auto is_valid = min(to_x, to_y) >= 0 
                                        && to_x < m  && to_y < n 
                                        && !mark[to_x][to_y];
                        if (is_valid) {
                            if (!mat[to_x][to_y]) return distance;
                            mark[to_x][to_y] = true;
                            temp.push_back({to_x, to_y});
                        }
                    }
                swap(temp, list);
            }
            throw "error"; 
        };
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j])
                    res[i][j] = go(i, j);
        return res;
    }
};
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp;
        
        for (vector<int>& row: mat) 
            dp.emplace_back(row.begin(), row.end());
        
        
        for (int row = 0; row < m; row++) 
            for (int col = 0; col < n; col++) {
                if (dp[row][col] == 0) continue;
                int minNeighbor = m * n;
                if (row) minNeighbor = min(minNeighbor, dp[row - 1][col]);
                if (col) minNeighbor = min(minNeighbor, dp[row][col - 1]);
                dp[row][col] = minNeighbor + 1;
            }
        
        for (int row = m - 1; row >= 0; row--) 
            for (int col = n - 1; col >= 0; col--) {
                if (dp[row][col] == 0) continue;
                int minNeighbor = m * n;
                if (row < m - 1) minNeighbor = min(minNeighbor, dp[row + 1][col]);
                if (col < n - 1)  minNeighbor = min(minNeighbor, dp[row][col + 1]);
                dp[row][col] = min(dp[row][col], minNeighbor + 1);
            }
        
        return dp;
    }
};

