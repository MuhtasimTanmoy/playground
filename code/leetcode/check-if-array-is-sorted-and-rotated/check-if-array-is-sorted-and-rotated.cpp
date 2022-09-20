class Solution {
public:
    bool check(vector<int>& nums) {
        
        int increment = 0;
        
        for(int i = 0; i < size(nums) - 1; i++) {
            if ( nums[i] > nums[i+1] ) {
                increment++;
            }
        }
        
        if ( nums[size(nums) - 1] > nums[0] ) {
            increment++;
        }
        
        // if [1,1,1] then increment <= 1
        // else increment = 1
        return increment <= 1;
        return increment <= 1;
    }
};