class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); i++) if (nums[i] <= 0) nums[i] = INT_MAX;
        
        for (auto i = 0; i < nums.size(); i++) {
            auto index = abs(nums[i]) - 1;
            if (index < 0 || index >= nums.size()) continue;
            nums[index] = -abs(nums[index]);
        }
        
        for (auto i = 0; i < nums.size(); i++) 
            if (nums[i] > 0)
                return i + 1;
        
        return nums.size() + 1;
    }
};