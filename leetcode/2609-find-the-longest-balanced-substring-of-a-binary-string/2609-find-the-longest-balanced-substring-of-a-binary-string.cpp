class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zero = 0, one = 0, res = 0;
        for (auto c: s) {
            if (c == '0') zero = one ? 1: zero + 1, one = 0;
            else {
                one++;
                res = max(res, 2 * min(one, zero));
            }
        }
        return res;
    }
};