class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1, itr = 1;
        while (itr < nums.size()) {
            if (nums[itr] != nums[itr-1]) {
                nums[left] = nums[itr];
                left++;
            }
            itr++;
        }
        return left;
    }
};