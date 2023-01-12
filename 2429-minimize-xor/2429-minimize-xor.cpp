class Solution {
public:
    int minimizeXor(int num1, int num2, int traverse = -1) {
        auto toAddInX = __builtin_popcount(num2) - __builtin_popcount(num1);
        while (toAddInX != 0) {
            auto isOne = num1 & (1 << ++traverse);
            if (toAddInX > 0 && !isOne) num1 |= 1 << traverse, toAddInX--;
            if (toAddInX < 0 && isOne) num1 ^= 1 << traverse, toAddInX++;
        }
        return num1;
    }
};