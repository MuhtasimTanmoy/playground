class Solution {
public:
    int minFlipsMonoIncr(string s, int res = 0, int num1 = 0) {
        for (auto c: s) {
            if (c == '0') res = min(num1, res + 1);
            else num1++;
        }
        return res;
    }
};