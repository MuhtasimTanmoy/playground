class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        for (int defaulter = 0, r = 0; r < nums.size(); r++)
            defaulter += !nums[r],
            defaulter -= defaulter > 1 ? !nums[l++]: 0;
        return nums.size() - l - 1;
    }
};