class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) ans[i] = nums[nums[i]];
        return ans;
    }
};