class Solution {
    enum dir {   
        topleft = -1, 
        bottomright = 1
    };
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
        int m =  g.size(), n = g[0].size();
        
        auto is_valid = [&](int x, int y) {
            if (min(x, y) < 0) return false;
            if (x == m || y == n) return false;
            return true;
        };
        
        auto count = [&](int x, int y, dir d) {
            unordered_set<int> cnt;
            while (is_valid(x, y)) 
                cnt.insert(g[x][y]),
                x += d,
                y += d;
            return cnt.size();
        };
        
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                auto tl = count(i - 1, j - 1, topleft),
                     br = count(i + 1, j + 1, bottomright);
                res[i][j] = abs(int(tl - br));
            }
        return res;
    }
};