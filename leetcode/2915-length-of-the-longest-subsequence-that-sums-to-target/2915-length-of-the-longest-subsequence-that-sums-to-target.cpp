class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& n, int t) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        
        int sz = n.size();
        function<int(int, int)> go = [&](auto i, auto sum) {
            if (sum == t) return 0;
            if (i == sz || sum > t) return INT_MIN;
            
            if (dp[i][sum] != -1) return dp[i][sum];
            
            auto with = 1 + go(i + 1, sum + n[i]), without = go(i + 1, sum);
            return dp[i][sum] = max(with, without);
            
        };
        auto res = go(0, 0);
        return res > 0 ? res: -1;
    }
};