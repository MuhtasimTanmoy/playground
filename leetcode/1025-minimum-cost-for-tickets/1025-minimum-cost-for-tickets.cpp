// class Solution {
// public:
//     int mincostTickets(vector<int>& D, vector<int>& C) {
//         vector<int> dp(366, -1);
//         function<int(int, int)> go = [&](auto i, auto upto) {
//             while (i < D.size() && D[i] < upto) ++i;
//             if (i == D.size()) return 0;
//             if (dp[i] != -1) return dp[i];
//             int res = INT_MAX;
//             res = min(res, C[0] + go(i + 1, D[i])),
//             res = min(res, C[1] + go(i + 1, D[i] + 7)),
//             res = min(res, C[2] + go(i + 1, D[i] + 30));
//             return dp[i] = res;
//         };
//         return go(0, 0);
//     }
// }

// class Solution {
// public:
//     int mincostTickets(vector<int>& D, vector<int>& C) {
//         int len = D.size();
//         vector<int> dp(len + 1, INT_MAX);
//         dp[len] = 0;

//         for (int i = len - 1; i >= 0; i--) 
//             dp[i] = min(dp[i], C[0] + dp[D[i]]),
//             dp[i] = min(dp[i], C[1] + dp[D[i] + 7]),
//             dp[i] = min(dp[i], C[2] + dp[D[i] + 30]);
//         return dp[0];
//     }
// };

class Solution {
public:
    int mincostTickets(vector<int>& D, vector<int>& C) {
        int len = D.size();
        vector<int> DP(len + 1, INT_MAX);
        DP[len] = 0;

        vector<int> days = {1, 7, 30};
        for (int i = len - 1; i >= 0; i--) {
            int now = i;
            for (auto j = 0; j < C.size(); j++) {
                while (now < len && D[now] < D[i] + days[j]) now++;
                DP[i] = min(DP[i], C[j] + DP[now]);
            }
        }
        return DP.front();
    }
};


// class Solution {
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = days.back();
//         vector<int> dp(n + 1);
//         for (int& day: days) dp[day] = INT_MAX;
//         for (int i = 1; i <= n; i++) 
//             if (dp[i] == 0) dp[i] = dp[i - 1];
//             else
//                 dp[i] = min({dp[i - 1] + costs[0],
//                              dp[max(0, i -  7)] + costs[1],
//                              dp[max(0, i - 30)] + costs[2]});
//         return dp[n];
//     }
// };


// class Solution {
// public:
//     using VI = vector<int>;
//     using fun = function<int(int, int)>;
//     using Map = unordered_map<int, int>;
//     int mincostTickets(VI& A, VI& cost, VI days = VI{1, 7, 30}, Map m = {}) {
//         int N = A.size();
//         VI dp(N + 1, int(1e9 + 7));  
//         dp[N] = 0;                 
//         for (auto i = N - 1; 0 <= i; --i) {
//             auto j = i ;
//             for (auto k = 0 ; k < 3; ++k) {
//                 while (j < N && A[j] < A[i] + days[k])  ++j;
//                 dp[i] = min(dp[i], cost[k] + dp[j]);
//             }
//         }
//         return dp[0];
//     }
// };