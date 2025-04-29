// class Solution {
// public:
//     int longestPalindromicSubsequence(string s, int k) {
//         function<int(int, int, int)> go = [&](auto l, auto r, int left) {
//             if (l > r) return 0;

//             auto dist = abs(s[l] - s[r]); dist = min(dist, 26 - dist);

//             if (s[l] == s[r])
//                 return 1 + l != r ? 1: 0 + go(l + 1, r - 1, left);
//             else if (l != r && dist <= left)
//                 return 2 + go(l + 1, r - 1, left - dist);
//             else return max(go(l + 1, r, left), go(l, r - 1, left));
//         };
//         return go(0, s.size() - 1, k);
//     }
// };


// class Solution {
// public:
//     int longestPalindromicSubsequence(string s, int k) {
//         vector<vector<int>> dp(s.size() + 1, vector<int>(k + 1, 0));
//         for (int i = s.size() - 1; i >= 0; i--) {
//             vector<vector<int>> now(s.size() + 1, vector<int>(k + 1, 0));
//             for (auto j = i + 1; j < s.size(); j++) {
//                 auto dist = abs(s[i] - s[j]); dist = min(dist, 26 - dist);
//                 for (auto p = k; p >= 0; p--) {
//                     if (s[i] == s[j]) now[j][p] = 2 + dp[j-1][p];
//                     else if (dist <= p) now[j][p - dist] = 2 + dp[j-1][p];
//                     else now[j][p] - max(now[j][p], now[j][p]);
//                 }
//             }
//             dp = now;
//         }
//         for (auto r: dp) {
//             for (auto n: r) {
//                 cout<<n<<" ";
//             }
//             cout<<endl;
//         }
//         return dp[s.size() - 1][0];
//     }
// };


class Solution {
public:
    int price(char p1, char p2) {
        return min(abs(p1 - p2), 26 - abs(p1 - p2));
    }
    
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector dp(n, vector(n, vector(k + 1, 0))); 

        for (int i = 0; i < n; i++) fill(dp[i][i].begin(), dp[i][i].end(), 1);

        for (int sz = 2; sz <= n; sz++)  
            for (int i = 0, x = sz - 1; x < n; i++, x++) 
                for (int j = 0; j <= k; j++) 
                    dp[i][x][j] = (s[i] == s[x]) ? 2 + dp[i + 1][x - 1][j] : 
                                  max({dp[i + 1][x][j], dp[i][x - 1][j], (j >= price(s[i], s[x]) ? 2 + dp[i + 1][x - 1][j - price(s[i], s[x])] : 0)});

        return dp[0][n - 1][k];
    }
};