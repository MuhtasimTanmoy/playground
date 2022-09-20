class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consOneCount = 0;
        int maxConsOneCount = INT_MIN;
        for(auto num: nums) {
            if (num) consOneCount++;
            else consOneCount = 0;
            maxConsOneCount = max(maxConsOneCount, consOneCount);
        }
        return maxConsOneCount;
    }
};