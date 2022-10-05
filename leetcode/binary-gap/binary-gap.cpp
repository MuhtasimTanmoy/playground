class Solution {
public:
    int binaryGap(int n) {
        
        int itr = 0;
        
        int maxDistance = 0;
        int distance = 1;
        
        bool countOngoing = false;
        
        while( itr < 31 ) {
            
            if ( (( n >> itr ) & 1) == 1 ) {
                
                if ( countOngoing ) {
                    maxDistance = max(maxDistance, distance);
                    distance = 1;
                }
                
                countOngoing = true;
            } else if ( countOngoing ) { distance++; }
            
            itr++;
        }
        
        return maxDistance;
    }
};