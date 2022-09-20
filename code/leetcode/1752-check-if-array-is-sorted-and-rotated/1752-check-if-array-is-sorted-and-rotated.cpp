class Solution {
public:
    bool check(vector<int>& nums) {
        int irregularCount = 0;
        for(int i = 0; i < size(nums) - 1; i++)
            if (nums[i] > nums[i+1]) irregularCount++;
        bool isFullSorted = irregularCount == 0 && nums[0] <= nums[size(nums)-1];
        bool isRotatedSorted = irregularCount == 1 && nums[0] >= nums[size(nums)-1];
        return isFullSorted || isRotatedSorted;
    }
};