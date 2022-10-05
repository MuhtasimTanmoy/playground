class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        bool hillPossible = false, valleyPossible = false;
        int result = 0;
        
        for(int i = 1; i < size(nums); i++) {
            
            if (nums[i-1] == nums[i]) continue;
                
            if (nums[i-1] > nums[i]) {
                if (hillPossible) result++;
                valleyPossible = true;
                hillPossible = false;
            } else {
                if (valleyPossible) result++;
                valleyPossible = false;
                hillPossible = true;
            }
        }
        
        return result;
    }
};