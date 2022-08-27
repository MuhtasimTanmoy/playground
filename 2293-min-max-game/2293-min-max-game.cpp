class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int counter = 0;
        while (true) {
            int index = 0;
            int len = nums.size() >> counter++;
            for (int i = 0; i < len; i += 2) {
                auto isEven = (index & 1) == 0;
                nums[index] = isEven ? min(nums[i], nums[i+1]) : max(nums[i], nums[i+1]);
                index++;
            }
            if (len == 2) break;
        }
        return nums[0];
    }
};