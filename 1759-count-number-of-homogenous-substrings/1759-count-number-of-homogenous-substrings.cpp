class Solution {
    int mod = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int count = 1;
        int res = 1;
        for(int i = 1; i < size(s); i++) {
            res = (s[i] == s[i-1] ? res + 1 : 1);
            count = ( count + res ) % mod;
        }
        return count;
    }
};