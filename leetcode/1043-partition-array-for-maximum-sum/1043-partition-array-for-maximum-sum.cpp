class Solution {
public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         map<int, int> pre_tracker, post_tracker;
//         vector<int> pre(n), post(n);
        
//         for (int i = 0, j = 0; i < n; i++) {
//             pre_tracker[arr[i]]++;
//             if (i - j >= k) 
//                 if (--pre_tracker[arr[j]] == 0)
//                     pre_tracker.erase(arr[j++]);
//             pre[i] = pre_tracker.rbegin()->first;
//         }     
                
//         for (int i = n - 1, j = n - 1; i >= 0; i--) {
//             post_tracker[arr[i]]++;
//             if (j - i >= k) 
//                 if (--post_tracker[arr[j]] == 0)
//                     post_tracker.erase(arr[j--]);
//             post[i] = post_tracker.rbegin()->first;
//         }
        
//         int res = 0;
//         for (int i = 0; i < n; i++) res += max(pre[i], post[i]);
//         return res;
//     }
    
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            int curMax = 0, best = 0;
            for (int k = 1; k <= K && i - k >= 0; ++k) 
                curMax = max(curMax, A[i - k]),
                best = max(best, dp[i - k] + curMax * k);
            dp[i] = best; 
        }
        return dp[N];
    }
}; 