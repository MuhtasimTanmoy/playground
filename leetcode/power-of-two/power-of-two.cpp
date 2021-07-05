class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int oneCount = 0;
        if( n < 0) { return false; }
        
        for(int i = 0; i < 32; i++) {
            
            if ( n & (1 << i) ) {
                oneCount++;
            }
            
        }
        
        return oneCount == 1;
    }
};