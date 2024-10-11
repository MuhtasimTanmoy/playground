class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto max_elem = *max_element(nums.begin(), nums.end());
        
        int max_len = 1;
        for (auto i = 0, count = 0; i < nums.size(); i++) {
            if (nums[i] == max_elem) count++; else count = 0;
            max_len = max(max_len, count);
        }
        return max_len;
    }
};