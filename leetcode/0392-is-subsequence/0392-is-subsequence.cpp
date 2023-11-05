class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<string, bool> dp;
        auto gen_key = [](int a, int b) {
            return to_string(a) + "-" + to_string(b);
        };
        
        function<bool(int, int)> go = [&](auto i, auto j) {
            if (i == s.size()) return true;
            if (i > s.size() || j >= t.size()) return false;
            
            auto key = gen_key(i, j);
            if (dp.count(key)) return dp[key];
            
            return dp[key] = s[i] == t[j] ? go(i + 1, j + 1) :  go(i, j + 1);
        };
        return go(0, 0);
    }
};