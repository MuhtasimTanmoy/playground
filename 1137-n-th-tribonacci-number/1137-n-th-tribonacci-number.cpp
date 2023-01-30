class Solution {
public:
    int tribonacci(int n) {
        if (!n) return 0;
        auto t0 = 0, t1 = 1, t2 = 1;
        
        n = n - 2;
        if (n <= 0) return 1;
        
        while (n--) {
            auto calc = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = calc;
        }
        return t2;
    }
};