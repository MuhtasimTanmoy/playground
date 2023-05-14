/*
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& g) {
        int m = g.size() - 1, n = g[0].size() - 1;
        auto is_valid = [&](auto i, auto j) {
            if (i > m) return false;
            if (j > n) return false;
            return true;
        };
        auto gen_key = [](int l, int r, string s) {
            return to_string(l) + "-" + to_string(r) + "-" + s;
        };
        unordered_map<string, bool> dp;
        function<bool(int, int, string&)> go = [&](auto i, auto j, auto s) {
            if (!is_valid(i, j)) return false;
            if (i == m && j == n) 
                return s.back() == '(' && g[i][j] == ')' && s.size() == 1;
            auto key = gen_key(i, j, s);
            if (dp.count(key)) return dp[key];
            if (g[i][j] == '(') s += '(';
            else {
                if (s.back() != '(') return false;
                s.pop_back();
            }
            auto to_left = go(i, j + 1, s),
                 to_down = go(i + 1, j, s);
            return dp[key] = to_left || to_down;
        };
        string test = "";
        return go(0, 0, test);
    }
};

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& g) {
        int m = g.size() - 1, n = g[0].size() - 1;
        auto is_valid = [&](auto i, auto j) {
            if (i > m) return false;
            if (j > n) return false;
            return true;
        };
        auto gen_key = [](int l, int r, int s) {
            return to_string(l) + "-" + to_string(r) + "-" + to_string(s);
        };
        unordered_map<string, bool> dp;
        function<bool(int, int, int)> go = [&](auto i, auto j, auto s) {
            if (!is_valid(i, j)) return false;
            if (i == m && j == n) return g[i][j] == ')' && s == 1;
            
            auto key = gen_key(i, j, s);
            if (dp.count(key)) return dp[key];
            
            if (g[i][j] == '(') s++;
            else {
                if (s <= 0) return false;
                s--;
            }
            auto to_left = go(i, j + 1, s), to_down = go(i + 1, j, s);
            return dp[key] = to_left || to_down;
        };
        
        return go(0, 0, 0);
    }
};
*/

class Solution {
    int visited[100][100][101] = {};
public:
    bool hasValidPath(vector<vector<char>>& grid, int i = 0, int j = 0, int bal = 0) {
        int m = grid.size(), n = grid[0].size();
        bal += grid[i][j] == '(' ? 1 : -1;
        
        if (bal < 0 || bal > (m + n) / 2 || visited[i][j][bal]) return false;
        visited[i][j][bal] = true;
        
        if (i == m - 1 && j == n - 1 && bal == 0) return true;
        if (i < m - 1 && hasValidPath(grid, i + 1, j, bal)) return true;
        if (j < n - 1 && hasValidPath(grid, i, j + 1, bal)) return true;
        return false;
    }
};
