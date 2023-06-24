class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2) return -1;
        partial_sort(nums.begin(), nums.begin() + 2, nums.end());
        return nums[1];
    }
};