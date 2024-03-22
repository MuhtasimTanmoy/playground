// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         vector<int> dp(nums.size());
//         sort(nums.begin(), nums.end());
//         for (auto i = 1; i < nums.size(); i++)
//              for (auto j = 0; j < i; j++) 
//                  if (nums[i] % nums[j] == 0)
//                     dp[i] = max(dp[i], dp[j] + 1);
//         auto max_idx = 0;
//         for (auto i = 0, now = 0; i < nums.size(); i++)
//             if (dp[i] > now) 
//                 now = dp[i], max_idx = i;
//         vector<int> res;
//         for (int i = 0; i <= max_idx; i++) {
//             auto is_prev = res.size() ? nums[i] % res.back() == 0 : true;
//             if (is_prev && nums[max_idx] % nums[i] == 0)
//                 res.push_back(nums[i]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), curr_max = 0;
        vector<int> res, cache, dp(nums.size(), -1);
        
        function<void(int)> go = [&](auto i) {
            if (i == n) {
                if (res.size() > curr_max) curr_max = res.size(), cache = res;
                return;
            }
            go(i + 1);
            auto can_take = res.size() ? nums[i] % res.back() == 0 : true;
            // cout<<(dp[i] < (int) res.size())<<endl;
            if (can_take && dp[i] < (int) res.size())
                dp[i] = res.size(),
                res.push_back(nums[i]),
                go(i + 1),
                res.pop_back();
        };
        go(0);
        return cache;
    }
};