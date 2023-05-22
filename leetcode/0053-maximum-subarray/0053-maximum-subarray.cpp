class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int add = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            add = nums[i] + max(add, 0),
            res = max(res, add);
        }
        return res;
    }
};