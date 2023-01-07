class Solution {
public:
    int xorBeauty(vector<int>& nums, int ans = 0) {
//         int result = 0;
//         vector<int> mid;
//          for (int i = 0; i < nums.size(); i++)
//             for (int j = 0; j < nums.size(); j++) 
//                 mid.push_back(nums[i] | nums[j]);
        
//         for (int i = 0; i < nums.size(); i++)
//             for (int k = 0; k < nums.size(); k++) {
//                     int val = (nums[i] | nums[j]) & nums[k];
//                     result ^= val;
//                 }
//         return result;
        for (int x: nums) ans ^= x; return ans;
    }
};