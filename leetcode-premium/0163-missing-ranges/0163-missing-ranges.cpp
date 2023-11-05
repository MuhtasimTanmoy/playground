class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return {{lower, upper}};
        vector<vector<int>> res;
        if (nums.front() != lower) nums.insert(nums.begin(), lower - 1); 
        if (nums.back() != upper) nums.push_back(upper + 1);
        for (int i = 1; i < nums.size(); i++) 
            if (nums[i] - nums[i-1] > 1) {
                auto now = {nums[i-1] + 1, nums[i] - 1}; 
                res.push_back(now);
            }
        return res;
    }
};