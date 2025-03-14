class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0, res = 0, len = s.size();
        for (auto i = 0, l = 0; i < s.size(); i++) {
            a += s[i] == 'a' ? 1: 0;
            b += s[i] == 'b' ? 1: 0;
            c += s[i] == 'c' ? 1: 0;
            while (a && b && c) 
                res += len - i,
                a -= s[l] == 'a' ? 1: 0,
                b -= s[l] == 'b' ? 1: 0,
                c -= s[l] == 'c' ? 1: 0,
                l++;
        }
        return res;
    }
};