class Solution {
public:
    string longestPalindrome(string s) {
        auto check = [&](auto l, auto r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            return s.substr(l + 1, r - l - 1);
        };
        string res = s.substr(0, 1);
        for (auto i = 1; i < s.size(); i++) {
            auto now = check(i - 1, i + 1);
            if (now.size() > res.size()) res = now;
            if (s[i] == s[i - 1]) {
                now =  check(i - 2, i + 1);
                if (now.size() > res.size()) res = now;
            }
        }
        return res;
    }
};