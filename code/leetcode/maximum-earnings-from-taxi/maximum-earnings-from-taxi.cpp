class Solution {
public:
    using ll = long long;
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        vector<ll> dp(n+1);
        
        sort(rides.begin(), rides.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        
        int j = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            // j = i;
            while(j < rides.size() && rides[j][1] == i) {
                dp[i] = max(dp[i], dp[rides[j][0]] + i - rides[j][0] + rides[j][2]);
                j++;
            }
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     using ll = long long;
//     long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
//         vector<ll> dp(n+1, 0);
//         sort(rides.begin(), rides.end(), [](const vector<int> &a, const vector<int> &b){
//             return a[1] < b[1];
//         });
//         int j = 0;
//         for (int i = 1; i <= n; ++i) {
//             dp[i] = dp[i-1];
//             while (j < rides.size() && rides[j][1] == i) {
//                 dp[i] = max(dp[i], dp[rides[j][0]]+i-rides[j][0]+rides[j][2]);
//                 ++j;
//             }
//         }
//         return dp[n];
//     }
// };