class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero_count = 0, res = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (!nums[i]) zero_count++;
            while (zero_count > 1) zero_count -= nums[j++] == 0;
            res = max(res, i - j);
        }
        return res;
    }
};