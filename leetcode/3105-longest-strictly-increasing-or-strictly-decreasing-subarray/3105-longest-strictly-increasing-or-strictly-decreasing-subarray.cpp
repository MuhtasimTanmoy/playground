class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int run = 1, ans = 1; bool is_increasing = false;
        for (auto i = 1; i < nums.size(); i++) {
            auto l = nums[i - 1], r = nums[i];
            if (l < r) {
                if (!is_increasing) run = 1, is_increasing = true;
                ans = max(ans, ++run);
            } else if (l > r) {
                if (is_increasing) run = 1, is_increasing = false;
                ans = max(ans, ++run);
            } else 
                run = 1;
        }
        return ans;
    }
};