
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        auto sumNums = accumulate(nums.begin(), nums.end(), (long long) 0);
  
        long long sumAtIndex = 0,  minAvg = INT_MAX,  index = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sumAtIndex += nums[i];
            long long firstHalf = sumAtIndex / (i + 1);
            long long secondHalf = (i == n - 1) ? 0: (sumNums - sumAtIndex) / (n - i - 1);
            auto diff = abs(firstHalf - secondHalf);
            if (diff < minAvg) {
                minAvg = diff;
                index = i;
            }
        }
        return index;
    }
};