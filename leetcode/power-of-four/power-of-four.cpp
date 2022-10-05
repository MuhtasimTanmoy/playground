class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if ( n < 0 ) { return false; }
        
        int oneCount = 0;
        
        for(int i = 0; i < 31; i++) {
            
            if ( n & ( 1 << i ) ) {
                
                if ( i % 2 == 0) {
                    
                    oneCount++;
                    
                } else {
                    
                    return false;
                    
                }
                
            }
            
        }
        
        return oneCount == 1;
    }
};