/*
O(n) space
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) ans[i] = nums[nums[i]];
        return ans;
    }
};
*/


class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) 
            nums[i] += n * (nums[nums[i]] % n );
        for (int i = 0; i < nums.size(); i++) 
            nums[i] /= n;
        return nums;
    }
};