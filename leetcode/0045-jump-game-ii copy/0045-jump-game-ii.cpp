// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         unordered_map<int, int> cache;
//         function<int(int)> go = [&](auto idx) {
//             if (idx >= (nums.size() - 1)) return 0;
//             if (cache.count(idx)) return cache[idx];
//             int res = nums.size();
//             for (int i = 1; i <= nums[idx]; i++) res = min(res, 1 + go(idx + i));
//             return nums[idx] = res;
//         };
//         return go(0);
//     }
// };

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, n);
//         dp[0] = 0;
//         for (auto i = 0; i < n; i++) 
//             for (auto j = i + 1; j < min(n, i + nums[i] + 1); j++)
//                 dp[j] = min(dp[i] + 1, dp[j]);
//         return dp[n - 1];
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            auto till = nums[i-1];
            for (int j = i; j < min(i + till, n); j++) 
                dp[j] = min(dp[j], dp[i-1] + 1);
        }
        return dp[n-1];
    }
};