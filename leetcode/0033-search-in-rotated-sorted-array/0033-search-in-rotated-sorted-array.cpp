class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            auto m = l + (r - l) / 2;
            if (target == nums[m]) return m;
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target <= nums[m]) r = m - 1;
                else l = m + 1;
            } else {
                if (nums[m + 1] <= target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};