/*
class Solution {
public:
    int minInsertions(string s) {
        unordered_map<string, int> cache;
        auto gen_key = [](auto l, auto r) {
            return to_string(l) + "-" + to_string(r);
        };
        function<int(int, int)> go = [&](auto l, auto r) {
            if (l >= r) return 0;
            auto key = gen_key(l, r);
            if (cache.count(key)) return cache[key];
            if (s[l] == s[r]) return cache[key] = go(l + 1, r - 1);
            auto from_l = go(l + 1, r), from_r = go(l, r - 1);
            return cache[key] = 1 + min(from_l, from_r);
        };
        return go(0, s.size() - 1);
    }
};
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            vector<int> tmp(n + 1, 0);
            for (int j = 0; j < n; j++) 
                tmp[j + 1] = s[i] == s[n - 1 - j] 
                             ? dp[j] + 1: max(tmp[j], dp[j + 1]);
            swap(dp, tmp);
        }
        return n - dp[n];
    }
};