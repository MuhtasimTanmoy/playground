class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int consZeroCount = 0;
        int consOneCount = 0;
        
        int maxConsZeroCount = INT_MIN;
        int maxConsOneCount = INT_MIN;
        
        for(auto c: s) 
            if (c == '0') {
                consZeroCount++;
                consOneCount = 0;
                maxConsZeroCount = max(maxConsZeroCount, consZeroCount);
            } else {
                consZeroCount = 0;
                consOneCount++;
                maxConsOneCount = max(maxConsOneCount, consOneCount);
            }
        
        return maxConsOneCount > maxConsZeroCount;
    }
};