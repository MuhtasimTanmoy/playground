class Solution {
public:
    int arrangeCoins(int n) {
        auto left = 0, right = n;
        while ( left <= right ) {
            long mid = left + (right - left) / 2;
            long calc = mid * (mid + 1) / 2;
            if (calc == n) return mid;
            if (n < calc) right = mid - 1; else left = mid + 1;
        }
        return right;
    }
};