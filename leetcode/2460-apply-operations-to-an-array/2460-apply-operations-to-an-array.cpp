class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) 
            if (nums[i] && nums[i] == nums[i + 1]) 
                nums[i] *= 2, nums[i + 1] = 0;
    
        int left = 0;
        for (int i = 0; i < nums.size(); i++) 
            if (nums[i]) 
                nums[left++] = nums[i];
        
        while (left < nums.size()) nums[left++] = 0;
        return nums;
    }
};