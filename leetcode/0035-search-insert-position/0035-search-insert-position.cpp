class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            auto m = (l + r) >> 1;
            if (nums[m] == target) return m;
            if (nums[m] > target) r = m - 1; else l = m + 1;
        }
        return l;
    }
};