class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int i = 0; i < size(nums); i++) if (nums[i]) nums[left++] = nums[i];
        while(left < size(nums)) nums[left++] = 0;
    }
};