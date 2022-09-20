class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = size(nums);
        next_permutation(nums.begin(), nums.end());
    }
};