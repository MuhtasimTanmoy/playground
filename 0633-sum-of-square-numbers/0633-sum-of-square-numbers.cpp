class Solution {
public:
    bool judgeSquareSum(int c) {
        if (!c) return true;
        for (long long i = 1; i * i <= c; i++) {
            double otherSq = sqrt(c - i * i);
            int toInt = otherSq;
            if ( toInt == otherSq ) return true;
        }
        return false;
    }
};