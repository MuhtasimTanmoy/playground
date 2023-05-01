class Solution {
public:
    bool canCross(vector<int>& s) {
        if (s[0] + 1 != s[1]) return false;
        
        int n = s.size() - 1;
        unordered_map<string, bool> bag;
        auto gen_key = [](auto l, auto ...r) {
            return (to_string(l) + ... + ("-" + to_string(r)));
        };
        
        function<bool(int, int, int)> go = [&](auto i, auto val, auto offset) {
            if (val < s[i]) return false;
            if ( i == n ) return val == s[i];
            
            auto key = gen_key(i, val, offset);
            if (bag.count(key)) return bag[key];
            
            if (val > s[i]) return bag[key] = go(i + 1, val, offset);
            auto paths = go(i + 1, val + offset, offset) 
                      || go(i + 1, val + offset + 1, offset + 1)
                      || go(i + 1, val + offset - 1, offset - 1);
            return bag[key] = paths;
        };
        
        return go(1, 1, 1);
    }
};