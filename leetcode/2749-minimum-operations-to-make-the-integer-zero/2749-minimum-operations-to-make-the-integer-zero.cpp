class Solution {
public:
    int makeTheIntegerZero(long long l, long long r) {
        if (l < r) return -1;
        for (int i = 1; i < 100; i++) {
            l -= r;
            if (__builtin_popcountll(l) <= i && i <= l)
                return i;
        }
        return -1;
    }
};