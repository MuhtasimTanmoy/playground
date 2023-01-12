class Solution {
    // 0011001
    // 1001000
public:
    int minimizeXor(int num1, int num2) {
        auto x = num1;
        auto toAddInX = __builtin_popcount(num2) - __builtin_popcount(x);
        int traverse = 0;
        while (toAddInX != 0) {
            auto isOne = x & (1 << traverse);
            if (toAddInX > 0 && !isOne) {
                x |= 1 << traverse;
                toAddInX--;
            }
            if (toAddInX < 0 && isOne) {
                x ^= 1 << traverse;
                toAddInX++;
            }
            traverse++;
        }
        return x;
    }
};