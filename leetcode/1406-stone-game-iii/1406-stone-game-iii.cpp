// class Solution {
// public:
//     string stoneGameIII(vector<int>& sv) {
//         int n = sv.size();
//         unordered_map<int, int> dp;
//         function<int(int)> f = [&](int i) -> int {
//             if (i == n) return 0;
//             if (dp.count(i)) return dp[i];
//             int result = INT_MIN, sum = 0;
//             for (auto itr = i; itr < min(n, i + 3); itr++) 
//                 sum += sv[itr],
//                 result = max(result, sum - f(itr + 1));
//             return dp[i] = result;
//         };
//         auto diff = f(0);
//         if (!diff) return "Tie";
//         return diff > 0 ? "Alice": "Bob";
//     }
// };


class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i, take = 0; j < min(n, i + 3); j++)
                take += sv[j],
                dp[i] = max(dp[i], take - dp[j + 1]);
        if (!dp[0]) return "Tie";
        return dp[0] > 0 ? "Alice": "Bob";
    }
};