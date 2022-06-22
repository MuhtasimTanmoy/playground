class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + size(nums) - k + 1, nums.end());
        return nums[size(nums) - k];
    }
};