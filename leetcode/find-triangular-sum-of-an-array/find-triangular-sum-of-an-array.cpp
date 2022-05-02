class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int len = size(nums);
        while(len != 1) {
            for(int i = 0; i < len-1; i++) 
                nums[i] = (nums[i] + nums[i+1]) % 10;
            len--;
        }
        return nums[0];
    }
};