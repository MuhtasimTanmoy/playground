class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        int pre1 = 1;
        int pre2 = 0;
        
        for(int i = 2; i <= n; i++) {
            int curi = pre1 + pre2;
            pre2 = pre1;
            pre1 = curi;
        }
        return pre1;
    }
};