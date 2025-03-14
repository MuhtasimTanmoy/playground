class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int pre_min = 0, pre_max = 0, count = 0;
        for (auto num: nums) 
            count += num,
            pre_min = min(pre_min, count),
            pre_max = max(pre_max, count);
        return pre_max - pre_min;
    }
};