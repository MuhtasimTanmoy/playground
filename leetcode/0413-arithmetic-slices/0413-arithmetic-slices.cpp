class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, local = 0;
        for (int i = 1; i < nums.size() - 1; i++) 
            if (nums[i] - nums[i-1] == nums[i+1] - nums[i]) res += ++local;
            else local = 0;
        return res;    
    }
};