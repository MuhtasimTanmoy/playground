class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0;
        int right = size(nums) - 1;
        
        int leftIncons = 0;
        int rightIncons = 0;
        
        int minNums = INT_MAX;
        int maxNums = INT_MIN;
        
        int result = 0;
        while(left < size(nums) && right >= 0) {
            minNums = min(minNums, nums[right]);
            if (minNums < nums[right]) leftIncons = right;
            
            maxNums = max(maxNums, nums[left]);
            if (maxNums > nums[left]) rightIncons = left;
            
            right--;
            left++;
        }
        
        if (leftIncons == 0 && minNums == nums[0]) return 0;
        return rightIncons - leftIncons + 1;
    }
};