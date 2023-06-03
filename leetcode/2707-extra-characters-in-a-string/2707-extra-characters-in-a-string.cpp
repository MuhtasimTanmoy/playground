// class Solution {
// public:
//     int minExtraChar(string s, vector<string>& dict) {
//         unordered_map<int, int> dp;
//         unordered_set<string> bag(dict.begin(), dict.end());
//         function<int(int)> go = [&](auto i) {
//             if (i >= s.size()) return 0;
//             if (dp.count(i)) return dp[i];
            
//             string temp = ""; int res = s.size();
//             for (int itr = i; itr < s.size(); itr++) {
//                 temp += s[itr];
//                 int cur = bag.count(temp) ? 0: temp.size(),
//                     nxt = go(itr + 1);
//                 res = min(res, cur + nxt);
//             }
//             return dp[i] = res;
//         };
//         return go(0);
//     }
// };


class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> bag(dict.begin(), dict.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            string curr = ""; int res = s.size();
            for (int j = i; j < n; j++) {
                curr += s[j];
                int cur = bag.count(curr) ? 0: curr.size();
                res = min(res, cur + dp[j + 1]);
            }
            dp[i] = res;
        }
        return dp[0];
    }
};