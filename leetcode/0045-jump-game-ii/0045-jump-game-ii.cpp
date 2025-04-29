// class Solution {
// public:
//     int jump(vector<int>& N) {
//         vector<int> dp(N.size() + 1, -1);
//         function<int(int)> go = [&](auto i) {
//             if (i >= N.size() - 1) return 0;
//             if (dp[i] != -1) return dp[i];

//             int res = N.size();
//             for (auto j = 1; j <= N[i]; j++) 
//                 res = min(res, 1 + go(i + j));
//             return dp[i] = res;
//         };
//         return go(0);
        
//     }
// };


class Solution {
public:
    int jump(vector<int>& N) {
        // vector<int> dp(N.size() + 1, -1);
        // function<int(int)> go = [&](auto i) {
        //     if (i >= N.size() - 1) return 0;
        //     if (dp[i] != -1) return dp[i];

        //     int res = N.size();
        //     for (auto j = 1; j <= N[i]; j++) res = min(res, 1 + go(i + j));
        //     return dp[i] = res;
        // };
        // return go(0);

        int len = N.size();
        vector<int> dp(len, len);
        dp[0] = 0;
        for (int i = 0; i < len; i++) 
            for (auto j = 1; j <= N[i]; j++) {
                if (i + j >= len) continue;
                dp[j + i] = min(dp[i] + 1, dp[j + i]);
            }
        return dp[N.size() - 1];
    }
};