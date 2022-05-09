class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        
        int sum = 0;
        for(auto num: nums) sum += num;
        
        int revSum = 0;
        for (int i = 0; i < size(nums); i++) {
            revSum += nums[i];
            if (revSum > (sum - revSum)) nums.resize(i+1);
        }
        return nums;
    }
};