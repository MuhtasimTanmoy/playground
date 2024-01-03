/*
// 341 / 345 test cases passed.
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<string, long long> dp;
        auto gen_key = [](int a, int b) {
            return to_string(a) + "-" +to_string(b);
        };
        function<long long(int, int)> go = [&](auto prev, auto i) {
            if (i == n) return 0LL;
            auto key = gen_key(prev, i);
            if (dp.count(key)) return dp[key];
            auto res = go(prev, i + 1);
            auto is_valid = (prev == -1)
                || ( prev != -1 && (nums[i] - nums[prev]) >= (i - prev));
            if (is_valid)
                res = max(res, nums[i] + go(i, i + 1));
            return dp[key] = res;
        };
        auto res = go(-1, 0);
        if (!res) return *max_element(nums.begin(), nums.end());
        return res;
    }
};

// 341 / 345 test cases passed.
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) 
                if (nums[i] - i >= nums[j] - j)
                    dp[i] = max(dp[i], dp[j] + nums[i]);
        return *max_element(dp.begin(), dp.end());
    }
};
*/

// class Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<long long> dp(nums.begin(), nums.end());
//         for (int i = 1; i < n; i++)
//             for (int j = 0; j < i; j++) 
//                 if (nums[i] - i >= nums[j] - j)
//                     dp[i] = max(dp[i], dp[j] + nums[i]);
//         return *max_element(dp.begin(), dp.end());
//     }
// };

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {        
        auto n = nums.size();
        vector<int> idx(n, 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](auto i, auto j) {
            auto l = nums[i] - i, r = nums[j] - j;
            return l == r ? i < j: l < r;
        });
        vector<long long> BIT(n + 10, 0);
        auto get = [&](auto i) {
            long long ans = 0;
            while (i > 0) ans = max(ans, BIT[i]), i -= i & -i;
            return ans;
        };
        auto update = [&](auto i, auto val) {
            while (i < BIT.size())
                BIT[i] = max(val, BIT[i]), i += i & -i;
        };
        auto ans = LLONG_MIN;
        for (auto i = 0; i < n; i++) {
            auto ind = idx[i];
            long long sum = nums[ind];
            sum += get(ind + 1);
            update(ind + 1, sum);
            ans = max(ans, sum);  
        }
        return ans;
    }
};
