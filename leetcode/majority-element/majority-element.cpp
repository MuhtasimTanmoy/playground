class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return nums[size(nums)>>1];
    }
};