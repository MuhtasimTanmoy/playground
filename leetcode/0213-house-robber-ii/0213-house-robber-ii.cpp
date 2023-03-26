class Solution {
    int _rob(vector<int>& nums, int start) {
        auto prev_l = 0, prev_r = 0;
        for (int i = start; i < nums.size(); i++) {
            auto c = prev_r;
            prev_r = max(prev_r, prev_l + nums[i]);
            prev_l = c;
        }
        return prev_r;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        auto f = _rob(nums, 1);
        nums.pop_back();
        return max(f, _rob(nums, 0));
    }
};