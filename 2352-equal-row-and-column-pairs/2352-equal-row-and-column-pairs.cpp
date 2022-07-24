class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        auto n = size(grid);
        int res = 0;
        int k = 0;
        while (k < n) {
            for (int i = 0, j = 0; i < n ; i++) {
                for (j = 0; j < n; j++)  if (grid[j][k] != grid[i][j]) break;
                if (j == n) res++;
            }
            k++;
        }
        return res;
    }
};