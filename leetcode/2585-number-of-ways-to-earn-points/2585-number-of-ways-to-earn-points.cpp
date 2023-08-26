class Solution {
    int MOD = 1e9 + 7;
public:
//     int waysToReachTarget(int target, vector<vector<int>>& types) {
//         unordered_map<string, int> dp;
//         auto gen_key = [](int a, int b) {
//             return to_string(a) + "-" + to_string(b);
//         };
        
//         function<int(int, int)> go = [&](auto i, auto sum) {
//             if (sum == target) return 1;
//             if (i == types.size()) return 0;

//             auto key = gen_key(i, sum);
//             if (dp.count(key)) return dp[key];
            
//             auto res = 0;
//             auto count = types[i].front(), mark = types[i].back();
//             for (auto c = 1; c <= count; c++)
//                 if (sum + c * mark <= target)
//                     res = (res + go(i + 1, sum + c * mark)) % MOD;
//                 else break;
//             res = (res + go(i + 1, sum)) % MOD;
//             return dp[key] = res;
//         };
//         return go(0, 0);
//     }
    

    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
//         vector<int> dp(target + 1, 0);
//         dp[0] = 1;
        
//         for (auto type: types) {
//             auto count = type.front(), mark = type.back();
//             for (int i = 1; i <= target; i++)
//                 for (int j = 1; j <= count; j++)
//                     if (i - j * mark >= 0)
//                         dp[i] = (dp[i] + dp[i - j * mark]) % MOD;
//         }
//         return dp.back();
        
        vector<int> dp(target + 1);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for (auto& t : types)
            for (int i = target; i > 0; --i)
                for (int k = 1; k <= t[0] && i - t[1] * k >= 0; ++k)
                    dp[i] = (dp[i] + dp[i - t[1] * k]) % mod;
        return dp.back();
    }
};