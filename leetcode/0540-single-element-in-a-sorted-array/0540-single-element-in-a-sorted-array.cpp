class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        auto lo = 0, hi = n;
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (mid & 1) mid--;
            if (nums[mid] == nums[mid + 1]) lo = mid + 2; 
            else hi = mid;
        }
        return nums[lo];
    }
};