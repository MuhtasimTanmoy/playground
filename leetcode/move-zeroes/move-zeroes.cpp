class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int otherThanZeroIndex = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[otherThanZeroIndex] = nums[i];
                otherThanZeroIndex++;
            }
        }
        
        int zeroCount = nums.size() - otherThanZeroIndex;
        while(zeroCount--) {
            nums[nums.size() - 1 - zeroCount] = 0;
        }
    }
};