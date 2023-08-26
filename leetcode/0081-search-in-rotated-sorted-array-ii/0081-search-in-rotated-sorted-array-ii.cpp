class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            while (l < r && nums[l] == nums[l + 1]) l++;
            while (l < r && nums[r] == nums[r - 1]) r--;
            
            int m = (l + r) / 2;
            if (nums[m] == target) return true;
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target <= nums[m]) r = m - 1;
                else l = m + 1;
            } else {
                if (nums[m + 1] <= target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }
        return false;
    }
};