class Solution {
public:
    int countOdds(int low, int high) {        
        int count = 0;
        count += (high - low + 1) / 2;
        count += (high & low & 1);
        return count;
    }
};