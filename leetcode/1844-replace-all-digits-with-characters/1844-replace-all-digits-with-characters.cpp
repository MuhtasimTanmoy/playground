class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2) {
            auto shift = s[i] - '0';
            auto from = s[i-1] - 'a';
            s[i] = 'a' + ( from + shift ) % 26;
        }
        return s;
    }
};