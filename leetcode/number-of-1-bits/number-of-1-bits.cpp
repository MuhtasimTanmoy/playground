class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int oneCount = 0;
        
        for(int i = 0; i < 32; i++) {
            oneCount += ( 1 << i ) & n ? 1 : 0;
        }
        
        return oneCount;
    }
};