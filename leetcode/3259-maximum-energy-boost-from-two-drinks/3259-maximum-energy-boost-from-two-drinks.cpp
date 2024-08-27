class Solution {
public:
//     long long maxEnergyBoost(vector<int>& A, 
//                              vector<int>& B) {
//         long long dp[100001][2];
//         memset(dp, -1, sizeof(dp));
//         int n = A.size();
//         function<long long(int, bool)> go = [&](auto i, auto a_taken) {
//             if (i >= n) return 0LL;
//             if (dp[i][a_taken ? 1 : 0] != -1) return dp[i][a_taken ? 1 : 0];
//             long long local = 0;
//             if (a_taken)
//                 local = A[i] + go(i + 1, true),
//                 local = max(local, go(i + 1, false));
//             else
//                 local = B[i] + go(i + 1, false),
//                 local = max(local, go(i + 1, true));
//             return dp[i][a_taken ? 1 : 0] = local;
//         };
//         return max(go(0, true), go(0, false));
//     }
    
    
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        long long a0 = 0, a1 = 0, b0 = 0, b1 = 0, n = A.size();
        for (int i = 0; i < n; i++) {
            a1 = max(a0 + A[i], b0);
            b1 = max(b0 + B[i], a0);
            a0 = a1; b0 = b1;
        }
        return max(a1, b1);
    }
};

// https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/discuss/5653166/JavaC%2B%2BPython-DP-O(1)-Space