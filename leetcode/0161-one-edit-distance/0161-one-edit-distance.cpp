class Solution {
public:
    /*
    bool isOneEditDistance(string s, string t) {
        unordered_map<string, bool> um;
        auto gen_key = [](auto a, auto b) {
            return to_string(a) + "-" + to_string(b);
        };
        
        function<bool(int, int, bool)> go = [&](auto i, auto j, auto redeemed) {
            if (i == s.size() && j == t.size()) return redeemed;
            if (i == s.size() || j == t.size()) {
                if (redeemed) return false;
                else if (i == s.size()) return go(i, j + 1, true);
                else return go(i + 1, j, true);
            }
            
            auto key = gen_key(i, j);
            if (um.count(key)) return um[key];
            
            bool res = true;
            if (s[i] != t[j]) {
                if (redeemed) res = false;
                else res = go(i + 1, j, true) 
                           || go(i, j + 1, true) 
                           || go(i + 1, j + 1, true);
            } else res = go(i + 1, j + 1, redeemed);
            
            return um[key] = res;
        };
        
        return go(0, 0, false);
    }
    */
    
     bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s);
        for (int i = 0; i < m; i++) 
            if (s[i] != t[i]) {
                if (m == n) return s.substr(i + 1) == t.substr(i + 1);
                return s.substr(i) == t.substr(i + 1);
            }
        return m + 1 == n;
    }
    
};