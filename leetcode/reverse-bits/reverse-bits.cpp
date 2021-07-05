class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int l = 0;
        int r = 31;
        
        int store = 0;
        
        while( l < r ) {
            
            if ( (n >> l & 1) == (n >> r & 1) ) {
                l++;
                r--;
                continue;
            }
            
            n = n ^ ( 1 << l );
            n = n ^ ( 1 << r );
            
            l++;
            r--;
        }
        
        return n;
    }
};