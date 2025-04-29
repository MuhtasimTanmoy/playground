// class Solution {
//     int offset = 1000;
// public:
//     int findTargetSumWays(vector<int>& N, int t) {
//         t += offset;
//         vector<vector<int>> dp(N.size(), vector<int>(2001, -1));
//         function<int(int, int)> go = [&](auto i, auto sum) {
//             if (i == N.size()) return sum == t ? 1: 0;
//             if (dp[i][sum] != -1) return dp[i][sum];
//             auto add = go(i + 1, sum + N[i]),
//                  subs = go(i + 1, sum - N[i]);
//             return dp[i][sum] = add + subs;
//         };
//         return go(0, offset);
//     }
// };


class Solution {
public:
    int findTargetSumWays(vector<int>& N, int t) {
        vector<unordered_map<int, int>> dp(N.size() + 1);
        dp[N.size()][t] = 1;
        for (int i = N.size() - 1; i >= 0; i--) 
            for (auto [val, count]: dp[i + 1])
                dp[i][val + N[i]] += count,
                dp[i][val - N[i]] += count;
        return dp[0][0];
    }
};


// class Solution {
// public:
//     int findTargetSumWays(vector<int>& A, int T) {
//         unordered_map<int, int> pre;
//         pre[0] = 1;

//         for (auto x: A) {
//             unordered_map<int, int> cur;
//             for (auto [t, cnt]: pre) cur[t + x] += cnt, cur[t - x] += cnt;
//             swap(pre, cur);
//         }
//         return pre[T];
//     }
// };