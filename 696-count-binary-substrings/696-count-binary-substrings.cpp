class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, now = 1, res = 0;
        for (int i = 1; i <= size(s); i++) {
            if (i == s.size() || s[i-1] != s[i]) {
                res += min(prev, now);
                prev = now;
                now = 0;
            }
            now++;
        }
        return res;
    }
};