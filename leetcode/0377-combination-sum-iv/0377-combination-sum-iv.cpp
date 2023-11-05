class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> dp;
        auto gen_key = [](auto i, auto j) {
            return to_string(i) + "-" + to_string(j);
        };
        sort(nums.begin(), nums.end());
        function<int(int, int)> go = [&](auto i, auto sum) {
            if (sum > target) return 0;
            if (sum == target) return 1;
            if (i == n) return 0;
            
            auto key = gen_key(i, sum);
            if (dp.count(key)) return dp[key];
            
            int ways = 0;
            for (int j = 0; j < n; j++) ways += go(i, sum + nums[j]);
            return dp[key] = ways;
        };
        return go(0, 0);
    }
};