class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int prev_diff = 0, res = 0;
        for (auto i = 1, running = 1; i < nums.size(); i++) {
            auto diff = nums[i] - nums[i-1];
            if ((prev_diff + diff) == 0 && abs(diff) == 1) running++;
            else running = diff == 1 ? 2: 1;
            res = max(running, res);
            prev_diff = diff;
        }
        return res == 1 ? -1: res;
    }
};