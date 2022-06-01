class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n) return false;
        
        while(n != 1) {
            if (n % 2) return false;
            n = n >> 1;
        }
        return true;
    }
};