class Solution {
public:
    bool isPowerOfTwo(int n) {
        int itr = 32;
        int oneCount = 0;
        while (itr--) if ( n >> itr & 1 ) oneCount++;
        return n > 0 && oneCount == 1;
    }
};