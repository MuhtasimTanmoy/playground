class Solution {
    // long long dp[100000][2];
    unordered_map<string, long long> dp;
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        auto gen_key = [](int i, bool b) {
            return to_string(i) + "-" + to_string(b);
        };
        function<long long(int, bool)> go = [&](auto i, auto is_even) -> long long {
            if (i == n) return 0L;
            auto key = gen_key(i, is_even);
            if (dp.count(key)) return dp[key];
            // if (dp[i][is_even]) return dp[i][is_even];
            
            auto is_curr_even = (nums[i] % 2) == 0;
            auto overhead = is_curr_even == is_even ? 0: x;
            auto taken = nums[i] - overhead + go(i + 1, is_curr_even),
                 not_taken = go(i + 1, is_even);
            return dp[key] = max(taken, not_taken);
        };
        return nums[0] + go(1, (nums[0] % 2) == 0);
    }
};