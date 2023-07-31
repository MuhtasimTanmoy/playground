// class Solution {
// public:
//     int maximizeWin(vector<int>& prizePositions, int k) {
//         vector<int> line(1e5, 0);
//         for (auto pos: prizePositions) line[pos]++;
//         int max = 0, second_max = 0; 
//         for (int i = 0, curr = 0; i < line.size(); i++) {
//             curr += line[i];
//             if (curr > max) second_max = max, max = curr;
//             else if (curr > second_max) second_max = curr;
//             if (i >= k - 1) curr -= line[i - k + 1];
//         }
//         return max + second_max;
//     }
// };

class Solution {
public:
    int maximizeWin(vector<int>& P, int k) {
        int n = P.size(), res = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0, j = 0; i < n; i++) {
            while (P[j] < P[i] - k) j++;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1 + dp[j]);
        }
        return res;
    }
};