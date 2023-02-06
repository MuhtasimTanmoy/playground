/*
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            res.push_back(nums[i]);
            res.push_back(nums[n + i]);
        }
        return res;
    }
};
*/

// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         for (int i = n; i < nums.size(); i++)  nums[i] = 1001 * nums[i] + nums[i-n];
//         for (int left = 0, right = n; right < nums.size(); right++, left += 2) 
//             nums[left] = nums[right] % 1001, nums[left + 1] = nums[right] / 1001;
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = n; i < nums.size(); i++) nums[i] = 1001* nums[i] + nums[i-n];
        for (int left = 0, right = n; right < nums.size(); left += 2, right++) {
            nums[left] = nums[right] % 1001;
            nums[left + 1] =  nums[right] / 1001;
        }
        return nums;
    }
};