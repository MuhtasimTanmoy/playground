class Solution {
    int max(int a, int b) {
        return a > b ? a: b;
    }
public:
    int countElements(vector<int>& nums) {
        
        if( size(nums) <= 2) return 0;
        
        sort(nums.begin(), nums.end());
        
        int substract = 0;

        int itr = 0;
        while(nums[itr++] == nums[0] && itr < size(nums)) substract++;
        
        itr = size(nums) - 1;
        while(nums[itr--] == nums[size(nums)-1] && itr >= 0) substract++;
        
        return max(size(nums) - substract, 0);
    }
};