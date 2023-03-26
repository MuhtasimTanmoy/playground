class Solution {
public:
    int longestContinuousSubstring(string s) {
        int local = 1, res = 1;
        for (int i = 1; i < s.size(); i++) {
            local = s[i] - s[i-1] == 1 ? local + 1: 1;
            res = max(res, local);
        }
        return res;
    }
};