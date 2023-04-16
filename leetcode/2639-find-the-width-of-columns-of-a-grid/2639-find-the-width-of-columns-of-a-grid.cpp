class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> res;
        for (int i = 0; i < grid[0].size(); i++) {
            int width = 0;
            for (int j = 0; j < grid.size(); j++) {
                int item_width = to_string(grid[j][i]).size();
                width = max(width, item_width);
            }
            res.push_back(width);
        }
        return res;       
    }
};