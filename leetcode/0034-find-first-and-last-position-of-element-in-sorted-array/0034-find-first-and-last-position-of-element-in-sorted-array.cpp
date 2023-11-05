class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue;
            if (res.empty()) res.push_back(i), res.push_back(i);
            else res.back() = i;
        }
        if (res.size() == 2) return res;
        return {-1, -1};
    }
};