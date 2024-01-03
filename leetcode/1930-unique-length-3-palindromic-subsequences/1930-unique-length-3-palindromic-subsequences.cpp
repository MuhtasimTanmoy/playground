class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> count(26, {-1, -1});
        for (auto i = 0; i < s.size(); i++) {
            auto idx = s[i] - 'a';
            auto &[f, l] = count[idx];
            if (f == -1) f = i; else l = i;
        }
        int res = 0;
        for (auto [f, l]: count) {
            if (f == -1 || l == -1) continue;
            if (l - f < 2) continue;
            unordered_set<char> bag;
            for (auto i = f + 1; i < l; i++) bag.insert(s[i]);
            res += bag.size();
        }
        return res;
    }
};