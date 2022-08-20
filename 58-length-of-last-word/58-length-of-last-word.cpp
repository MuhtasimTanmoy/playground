class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size() - 1;
        int ans = 0;
        while (len >= 0) {
            if (s[len] != ' ') ans++;
            else if (ans > 0) return ans;
            len--;
        }
        return ans;
    }
};