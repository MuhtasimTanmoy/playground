class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            k -= nums[i] == 0;
            if (k < 0) k += nums[j++] == 0;
            res = max(res, i - j + 1);
        }
        return res;
    }
};