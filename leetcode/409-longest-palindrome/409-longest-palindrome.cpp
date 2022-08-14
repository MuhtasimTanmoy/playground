class Solution {
public:
    int longestPalindrome(string s) {
        int mapping[127] = {0};
        for (auto c: s) mapping[c]++;
        int len = 0; bool singlePresent = false;
        for (auto m: mapping) {
            if (m >= 2) len += ((m >> 1) << 1);
            if (m & 1) singlePresent = true;
        }
        return len + (singlePresent ? 1: 0);
    }
};