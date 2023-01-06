class Solution {
public:
    int countTime(string t) {
        int res = 1;
        if (t[0] == '?') res = t[1] == '?' ? 24 : t[1] < '4' ? 3 : 2;
        else if (t[1] == '?') res = t[0] < '2' ? 10 : 4;
        res *= (t[3] == '?' ? 6 : 1);
        res *= (t[4] == '?' ? 10 : 1);
        return res;
    }
};