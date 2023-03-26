class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.size() + s2.size() != s3.size()) return false;
        
        unordered_map<string, bool> cache;
        auto gen_key = [](auto first, auto... rest) {
            return (to_string(first) + ... + ("-" + to_string(rest)));
        };
        
        function<bool(int, int, int)> go = [&](auto i1, auto i2, auto i3) {
            if (i3 == -1) return true;
            
            auto key = gen_key(i1, i2, i3);
            if (cache.count(key)) return cache[key];
            
            bool possible = false;
            if (i1 >= 0 && s1[i1] == s3[i3]) possible |= go(i1 - 1, i2, i3 - 1);
            if (i2 >= 0 && s2[i2] == s3[i3]) possible |= go(i1, i2 - 1, i3 - 1);
            return cache[key] = possible;
        };
        return go(s1.size() - 1, s2.size() - 1, s3.size() - 1);
    }
};