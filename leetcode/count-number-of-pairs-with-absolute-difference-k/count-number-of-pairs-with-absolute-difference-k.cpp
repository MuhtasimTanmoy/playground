class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        
        for(int i = 0; i < size(nums) - 1; i++) 
            for(int j = i+1; j < size(nums); j++) 
                if (abs(nums[i] - nums[j]) == k) count++;
        
        return count;
    }
};