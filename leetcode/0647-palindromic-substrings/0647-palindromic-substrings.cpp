class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        function<void(int, int)> count = [&](auto l, auto r) {
            if (l < 0 || r >= s.size()) return;
            if (s[l] != s[r]) return;
            ans++;
            count(--l, ++r);
        };
        for (auto i = 0; i < s.size(); i++)
            count(i, i),
            count(i, i + 1);
        return ans;
    }
};