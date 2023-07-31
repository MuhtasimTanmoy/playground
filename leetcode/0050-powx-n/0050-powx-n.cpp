class Solution {
public:
    double myPow(double x, int n) {
        auto is_neg = n < 0;
        long long i = abs(n);
        double res = 1;
        while (i > 0) 
            if (i % 2 == 0) x = x * x, i /= 2;
            else res = res * x, i--;
        return is_neg ? 1 / res : res;
    }
};