class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));

        return max(
            nums[0] * nums[1] * nums[2], 
            max(
                nums[0] * nums[1] * nums[size(nums)-1],
                nums[size(nums)-1] * nums[size(nums)-2] * nums[size(nums)-3]
            )
        );
    }
};