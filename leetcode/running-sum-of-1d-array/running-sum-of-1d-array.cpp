class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rSum(size(nums));
        rSum[0] = nums[0];
        for(int i = 1 ; i < size(nums); i++) rSum[i] = rSum[i-1] + nums[i];
        return rSum;
    }
};