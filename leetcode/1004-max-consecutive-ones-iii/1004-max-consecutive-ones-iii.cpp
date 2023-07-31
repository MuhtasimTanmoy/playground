class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        for (int i = 0, defaulter = 0; i < nums.size(); i++) 
            defaulter += !nums[i],
            defaulter -= defaulter > k ? !nums[l++]: 0;
        return nums.size() - l;
    }
};