class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1, itr = 1;
        for (auto itr = 1; itr < nums.size(); itr++)
            if (nums[itr] != nums[itr-1])
                nums[left++] = nums[itr];
        return left;
    }
};