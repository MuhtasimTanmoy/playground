class Solution {
public:
    bool containsCycle(vector<vector<char>>& g) {
        int h = g.size(), w = g.back().size(); 
        vector<vector<bool>> seen(h, vector<bool>(w, false));
        
        int from_x = -1, from_y = -1; char now = ' ';
        function<bool(int, int, int)> go = [&](auto i, auto j, auto dist) {
            if (i == h || j == w || i < 0 || j < 0) return false;
            if (g[i][j] != now) return false;
            if (i == from_x && j == from_y && dist >= 4) return true;
            if (seen[i][j]) return false;

            seen[i][j] = true;
            return go(i + 1, j, dist + 1) 
                || go(i, j + 1, dist + 1) 
                || go(i - 1, j, dist + 1) 
                || go(i, j - 1, dist + 1);
        };
        
        for (auto i = 0; i < h - 1; i++)
            for (auto j = 0; j < w - 1; j++) {
                if (seen[i][j]) continue;
                if (g[i][j] == g[i][j+1] && g[i][j] == g[i+1][j]) {
                    from_x = i, from_y = j, now = g[i][j];
                    auto can_go = go(i, j, 0);
                    if (can_go) return true;
                }
            }
        return false;
    }
};