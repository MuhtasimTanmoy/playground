class Solution {
    const int maxLimit = INT_MAX / 10;
    const int minLimit = INT_MIN / 10;
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            auto pop = x % 10;
            x /= 10;
            if (res > maxLimit || (res == maxLimit && pop > 7)) return 0;
            if (res < minLimit || (res == minLimit && pop < -8)) return 0;
            res = res * 10 + pop;
        }
        return res;
    }
};