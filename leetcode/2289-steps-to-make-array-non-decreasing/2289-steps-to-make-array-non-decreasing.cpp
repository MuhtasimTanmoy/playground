class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<array<int,2>> dp;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int cnt = 0;
            while (dp.size() && nums[i] > dp.back()[1]) 
                cnt = max(cnt + 1, dp.back()[0]),
                dp.pop_back();
            dp.push_back({cnt, nums[i]});
        }
        return (*max_element(dp.begin(), dp.end()))[0];
    }
};