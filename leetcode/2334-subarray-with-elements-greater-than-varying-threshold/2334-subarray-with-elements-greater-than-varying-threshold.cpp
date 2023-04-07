class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> stk;
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            while (stk.size() && nums[i] < nums[stk.back()]) {
                auto min_in_range = nums[stk.back()]; stk.pop_back();
                auto j = stk.size() ? stk.back(): -1, range = i - j - 1;
                if (min_in_range > threshold / range) 
                    return range;
            }
            stk.push_back(i);
        }
        return -1;
    }
};