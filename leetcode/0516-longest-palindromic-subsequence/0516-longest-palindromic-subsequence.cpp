/*
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        unordered_map<string, int> cache;
        auto gen_key = [](auto l, auto ...r) {
            return (to_string(l) + ... + ( "-" + to_string(r)));
        };
        function<int(int, int)> go = [&](auto l, auto r) {
            if (l < 0 || r == s.size()) return 0;
            
            auto key = gen_key(l, r);
            if (cache.count(key)) return cache[key];
            
            int point = 0;
            if (s[l] == s[r]) point += 1 + (l != r) + go(l - 1, r + 1);
            else point += max(go(l - 1, r), go(l, r + 1));
            return cache[key] = point;
        };
        int res = 1;
        for (int i = 0; i < s.size() - 1; i++) 
            res = max(res, max(go(i, i), go(i, i + 1)));
        return res;
    }
};
*/  

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        unordered_map<string, int> cache;
        auto gen_key = [](auto l, auto ...r) {
            return (to_string(l) + ... + ( "-" + to_string(r)));
        };
        function<int(int, int)> go = [&](auto l, auto r) {
            if (l > r) return 0;
            
            auto key = gen_key(l, r);
            if (cache.count(key)) return cache[key];
            
            int point = 0;
            if (s[l] == s[r]) point += 1 + (l != r) + go(l + 1, r - 1);
            else point += max(go(l + 1, r), go(l, r - 1));
            return cache[key] = point;
        }; 
        return go(0, s.size() - 1);
    }
};