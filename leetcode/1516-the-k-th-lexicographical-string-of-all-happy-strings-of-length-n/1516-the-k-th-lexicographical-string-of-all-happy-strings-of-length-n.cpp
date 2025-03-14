class Solution {
public:
    string getHappyString(int n, int &k, int p = 0, char last_ch = 0) {
        if (p == n)
            --k;
        else
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                if (ch != last_ch) {
                    auto res = getHappyString(n, k, p + 1, ch);
                    if (k == 0)
                        return string(1, ch) + res;
                }
            }
        return "";
    }
};