// 533 / 554 test cases passed.
// class Solution {
// public:
//     long long maximumTotalDamage(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         unordered_map<int, int> dp[n];
//         function<int(int, int)> go = [&](auto i, auto prev) {
//             if (i == n) return 0;
//             if (dp[i].count(prev)) return dp[i][prev];
//             auto res = 0;
//             if (nums[i] == prev)
//                 res = nums[i] + go(i + 1, nums[i]);
//             else if (nums[i] > prev + 2)
//                 res = nums[i] + go(i + 1, nums[i]),
//                 res = max(res, go(i + 1, prev));
//             else res = max(res, go(i + 1, prev));
//             return dp[i][prev] = res;
//         };
//         return go(0, -2);
//     }
// };


class Solution {
public:
   long long maximumTotalDamage(vector<int>& power) {
        long long dp[100001] = {0}, max_dp = 0;
        sort(begin(power), end(power));
        long long res = 0;
        for (int i = 0, j = 0; i < power.size(); ++i)  {      
            if (power[i] == power[max(0, i - 1)])
                dp[i + 1] = power[i] + dp[i];
            else {
                while(power[j] + 2 < power[i])
                    max_dp = max(max_dp, dp[++j]);
                dp[i + 1] = power[i] + max_dp;
            }
            res = max(res, dp[i + 1]);
        }
        return res;
    }
};