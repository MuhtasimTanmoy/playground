// class Solution {
//     int compute(int i, int j, string s) {
//         while (i >= 0 && j < s.size()) {
//             if (s[i] != s[j])  return j - i - 1;
//             i--, j++;
//         }
//         return j - i - 1;
//     }

//     int largest_palindrome_len(string s) {
//         int res = 1;
//         for (auto i = 0; i < s.size() - 1; i++) 
//             res = max(res, compute(i, i + 1, s)),
//             res = max(res, compute(i, i, s));
//         return res;
//     }

// public:
//     int longestPalindrome(string s, string t) {
//         auto s_len = largest_palindrome_len(s),
//              t_len = largest_palindrome_len(t);

//         int res = max(s_len, t_len);
//         reverse(t.begin(), t.end());
//         for (auto i = 0; i < s.size(); i++) {
//             auto len = s.size() - i;
//             int j = i;
//             while (j >= 0) {
//                 auto now = s.substr(j--, len);
//                 auto is_l_suff = s.ends_with(now);
//                 auto try_to_find = t.find(now);
//                 if (try_to_find != -1) {
//                     auto is_r_suff = t.ends_with(now);
//                     auto is_mid_not_possible = is_l_suff && is_r_suff;
//                     int ret = (is_mid_not_possible ? 0: 1) + 2 * now.size();
//                     res = max(ret, res);
//                 } 
//             }
//         }
//         int total = s.size() + t.size();
//         return min(res, total);
//     }
// };



class Solution {
public:
    bool checkPal(string &s, int l, int r) {
        for (; l < r; ++l, --r)
            if (s[l] != s[r])
                return false;
        return true;
    }

    vector<int> longestPalindromes(string &s) {
        int n = s.size();
        vector<int> res(n + 1, 0);
        for (int i = 0; i < n; ++i)
            for (int j = n - 1; i <= j && res[i] < 2; --j)
                res[i] = checkPal(s, i, j) ? j - i + 1 : 1;
        return res;
    }
    
    int longestPalindrome(string s, string t) {
        reverse(begin(t), end(t));
        vector<int> s_pal = longestPalindromes(s), t_pal = longestPalindromes(t);
        int m = s.size(), n = t.size(), res = 0;
        int dp[1001][1001] = {};  
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (s[i] == t[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;    
                else
                    dp[i + 1][j + 1] = 0;
                res = max(res, 2 * dp[i + 1][j + 1] 
                    + max(s_pal[i + (s[i] == t[j])] , t_pal[j + (s[i] == t[j])]));
            }
        return res;                
    }
};
