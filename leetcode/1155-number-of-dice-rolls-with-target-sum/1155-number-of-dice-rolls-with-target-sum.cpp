class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        function<int(int, int)> traverse = [&](int index, int sum) -> int {
            if (index == n) return sum == target;
            if (sum > target) return 0;
            if (dp[index][sum] != -1) return dp[index][sum];
            
            int ways = 0;
            for (int i = 1; i <= min(k, target - sum); i++) 
                ways = (ways + traverse(index + 1, sum + i)) % MOD;
            return dp[index][sum] = ways;
        };
        return traverse(0, 0);
    }
};