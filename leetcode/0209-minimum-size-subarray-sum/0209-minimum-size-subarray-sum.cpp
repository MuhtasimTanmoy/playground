class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        for (int l = 0, r = 0, sum = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target && l <= r) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
        }
        return res == INT_MAX ? 0: res;
    }
};