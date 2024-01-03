class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0;
        for (auto i = 0; i < nums.size() - 1; i++)
            for (auto j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                    res = max(res, nums[i] ^ nums[j]);
            }
        return res;
    }
};