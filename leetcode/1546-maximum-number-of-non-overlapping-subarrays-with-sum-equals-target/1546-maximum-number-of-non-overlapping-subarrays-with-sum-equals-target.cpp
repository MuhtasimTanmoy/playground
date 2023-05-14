class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target, int res = 0) {
        unordered_map<int, int> dp;
        dp[0] = -1;
        for (int i = 0, sum = 0, right = -1; i < nums.size(); i++) {
            sum += nums[i];
            if (dp.count(sum - target)) {
                auto l = dp[sum - target];
                if (right <= l) res++, right = i;
            }
            dp[sum] = i;
        }
        return res;
    }
};