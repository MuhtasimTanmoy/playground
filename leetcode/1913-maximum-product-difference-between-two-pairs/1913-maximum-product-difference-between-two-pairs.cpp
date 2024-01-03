class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        return nums.back() * nums[n - 1] - nums.front() * nums[1];
    }
};