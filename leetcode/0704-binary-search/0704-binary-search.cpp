class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            auto m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};