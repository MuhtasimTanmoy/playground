class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, counting = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) counting++; else counting = 1;
            res = max(res, counting);
        }
        return res;
    }
};