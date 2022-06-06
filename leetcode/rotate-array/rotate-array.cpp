class Solution {
public:
    void rotate(vector<int>& nums, int k) {   
//         vector<int> result(size(nums));
//         for (int i = 0; i < size(nums); i++) {
//             int target = ( i + k ) % size(nums);
//             result[target] = nums[i];
//         }
        
//         for (int i = 0; i < size(nums); i++)
//             nums[i] = result[i];
        
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};