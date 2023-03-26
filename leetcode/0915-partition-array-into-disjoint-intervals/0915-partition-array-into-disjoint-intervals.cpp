class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        auto min_so_far = nums[0], max_taken_for_right = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) 
            if (nums[i] < min_so_far) {
                min_so_far = max_taken_for_right;
                ans = i;
            } else if (nums[i] > max_taken_for_right) max_taken_for_right = nums[i];
        return ans + 1;
    }
};