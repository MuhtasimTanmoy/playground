class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0], sum = nums[0];
        for (int i = 1; i < size(nums); i++) {
            if (nums[i-1] < nums[i]) sum += nums[i]; else sum = nums[i];
            res = max(res, sum); 
        }
        return res;
    }
};