class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                auto to = min(s[l], s[r]);
                s[l] = to, s[r] = to;
            }
            l++, r--;
        }
        return s;
    }
};