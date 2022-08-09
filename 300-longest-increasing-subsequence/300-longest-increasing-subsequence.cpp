class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
            if (it != sub.end()) *it = nums[i];
            else sub.push_back(nums[i]);
        }
        return sub.size();
    }
};