class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &row: grid) sort(row.begin(), row.end());
        int ans = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            int res = INT_MIN;
            for (int j = 0; j < grid.size(); j++) 
                res = max(grid[j][i], res);
            ans += res;  
        }
        return ans;
    }
};