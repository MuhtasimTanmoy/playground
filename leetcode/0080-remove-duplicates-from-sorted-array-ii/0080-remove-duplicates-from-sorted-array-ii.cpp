class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = -1, count = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == prev) count++; else count = 0;
            if (count < 2) nums[left++] = nums[i];
            prev = nums[i];
        }
        return left;
    }
};