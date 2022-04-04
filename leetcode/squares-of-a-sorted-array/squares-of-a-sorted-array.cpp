class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int left = 0;
        int right = size(nums) - 1;
        
        int traverse = size(nums) - 1;
            
        vector<int> result(size(nums));
        
        while ( traverse >= 0 ) {
            
            if ( abs(nums[left]) > abs(nums[right]) ) {
                result[traverse] = nums[left] * nums[left];
                left++;
            } else {
                result[traverse] = nums[right] * nums[right];
                right--;
            }
            traverse--;
            
        }
        
        return result;
    }
};