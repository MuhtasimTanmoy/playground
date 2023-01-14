class Solution {
public:
    int maxSubArray(vector<int>& nums, int res = INT_MIN, int local = 0) {
        for (auto num: nums) {
            local = num + max(local, 0);
            res = max(local, res);
        }
        return res;
    }
};