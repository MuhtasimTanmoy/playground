class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& start, string s) {
        auto is_out = [&n](auto x, auto y) {
            if (x < 0 || x == n) return true;
            if (y < 0 || y == n) return true;
            return false;
        };
        
        vector<int> res;
        for (auto i = 0; i < s.size(); i++) {
            auto x = start.front(), y = start.back();
            for (auto j = i; j <= s.size(); j++) {
                if (j < s.size()) {
                    if (s[j] == 'R') y++;
                    else if (s[j] == 'L') y--;
                    else if (s[j] == 'U') x--;
                    else if (s[j] == 'D') x++;
                }
                if (is_out(x, y) || j == s.size()) {
                    res.push_back(j - i);
                    break;
                }
            }
        }
        return res;
    }
};