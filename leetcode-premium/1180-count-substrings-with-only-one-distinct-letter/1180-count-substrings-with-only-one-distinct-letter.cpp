class Solution {
public:
    int countLetters(string s) {
        int len = s.size();
        int additive = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i]) {
                len += additive;
                additive++;
            } else additive = 1;
        }
        return len;
    }
};