class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2, 0));
        vector<vector<int>> directions = {{1, 1}, {0, 1}, 
                                          {1, 0}, {-1, 1}, 
                                          {1, -1}, {-1, -1}, 
                                          {-1, 0}, {0, -1}, 
                                          {0, 0}};
        for (int i = 1; i < grid.size() - 1; i++)
            for (int j = 1; j < grid.size() - 1; j++) 
                for (auto direction: directions) {
                    auto x = direction[0];
                    auto y = direction[1];
                    res[i-1][j-1] = max(grid[i+x][j+y], res[i-1][j-1]);
                }
        return res;
    }
};