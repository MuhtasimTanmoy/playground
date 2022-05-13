class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = nums[0];
        int maxSum = nums[0];
        
        for ( int i = 1; i < size(nums); i++ ) {
            sum = nums[i] + max(sum, 0);
            maxSum = max(sum, maxSum);
        }
        
        return maxSum;
    }
};