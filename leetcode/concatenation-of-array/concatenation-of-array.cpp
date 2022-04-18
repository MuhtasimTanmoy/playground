class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len =  size(nums);
        for(int i = 0; i < len; i++) nums.push_back(nums[i]);
        return nums;
    }
};