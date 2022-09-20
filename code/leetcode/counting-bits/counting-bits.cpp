class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result;
        
        
        auto countOneIn = [](int n) -> int {
            int countOne = 0;
            for(int i = 0; i< 32; i++) {
                if ( ( n >> i) & 1 ) 
                    countOne++;
            }
            return countOne;
        };
        
        
        for( int i = 0; i <= n; i++ ) {
            
            result.push_back(__builtin_popcount(i));
            
        }
        
        return result;
    }
};