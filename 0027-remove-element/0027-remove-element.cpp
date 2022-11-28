/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[left] = nums[i];
            if (nums[i] != val) left++;
        }
        return left;
    }
};
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) 
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else left++;
        return right;
    }
};