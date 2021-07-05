class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        bool zeroStart = false;
        
        for ( int i = 0; i < 31; i++ ) {
            
            if ( zeroStart ) { 
                if ( (( n >> i) & 1) != 0 ) {
                    return false;
                }
            }
            
            if  ( (( n >> i) & 1) ^ (( n >> i + 1) & 1) ) {
                
            } else {
                zeroStart = true;
            }
        }
        
        return true;
        
    }
};