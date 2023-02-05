class Solution {
public:
    int maxSum(vector<vector<int>>& grid, int res = 0) {
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                       {0, 0}, 
                                       {1, -1}, {1, 0}, {1, 1}};
        for (int i = 1; i < grid.size() - 1; i++)
            for (int j = 1; j < grid[i].size() - 1; j++) {
                int sum = 0;
                for (auto dir: dirs) sum += grid[i + dir.first][j + dir.second];
                res = max(res, sum);
            }
        return res;
    }
};