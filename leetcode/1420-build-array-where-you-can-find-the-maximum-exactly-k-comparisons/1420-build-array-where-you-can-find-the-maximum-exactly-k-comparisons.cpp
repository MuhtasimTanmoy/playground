// class Solution {
//     int MOD = 1000000007;
// public:
//     int numOfArrays(int n, int m, int k) {
//         unordered_map<string, int> dp;
//         auto gen_key = [](auto a, auto ...b) {
//             return (to_string(a) + ... + ("-" + to_string(b)));
//         };
        
//         function<int(int, int, int)> go = [&](auto i, auto l, auto top) {
//             if (i == n) return l == 0 ? 1: 0;
//             if (l < 0) return 0;
            
//             auto key = gen_key(i, l, top);
//             if (!dp.count(key)) {
//                 dp[key] = 1;
//                 for (auto now = 1; now <= m; now++) 
//                     dp[key] += go(i + 1, l - (now > top), max(now, top)),
//                     dp[key] %= MOD;
//             }
//             return dp[key] - 1;
//         };
        
//         return go(0, k, -1);
//     }
// };


class Solution {
    int MOD = 1000000007;
    int dp[101][51][51] = {};
public:
    int numOfArrays(int n, int m, int k) {
        
        function<int(int, int, int)> go = [&](auto i, auto l, auto top) {
            if (i == n) return l == 0 ? 1: 0;
            if (l < 0) return 0;

            if (dp[top][i][l] == 0) {
                dp[top][i][l]  = 1;
                for (auto now = 1; now <= m; now++)
                    dp[top][i][l]  +=
                        go(i + 1, l - (now > top), max(now, top)),
                   dp[top][i][l]  %= MOD;
            }
            return dp[top][i][l]  - 1;
        };
        
        return go(0, k, 0);
    }
};