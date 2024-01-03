class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        auto c = grid.front().size(), r = grid.size();
        vector<int> rows(r), cols(c);
        for (auto i = 0; i < r; i++) 
            for (auto j = 0; j < c; j++) 
                if (grid[i][j])
                    cols[j]++, rows[i]++;
        for (auto i = 0; i < r; i++) 
            for (auto j = 0; j < c; j++) 
                grid[i][j] = cols[j] - (c - cols[j]) + rows[i] - (r - rows[i]);
        return grid;
    }
};