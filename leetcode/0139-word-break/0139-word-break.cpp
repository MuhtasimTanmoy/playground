class Solution {
public:
//     bool wordBreak(string s, vector<string>& dict) {
//         unordered_set<string> bag(dict.begin(), dict.end());
//         unordered_map<int, bool> um;
//         function<bool(int)> go = [&](auto i) {
//             if (i == s.size()) return true;
//             if (um.count(i)) return um[i];       
//             string builder = "";
//             bool is_pos = false;
//             for (auto j = i; j < s.size(); j++) {
//                 builder += s[j];
//                 if (bag.count(builder)) is_pos |= go(j + 1);
//             }
//             return um[i] = is_pos;
//         };
//         return go(0);
//     }
    
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> bag(dict.begin(), dict.end());
        int n = s.size();
        vector<bool> dp(n + 1); dp[0] = 1;
        queue<int> q; q.push(0);
        while (q.size()) {
            auto from = q.front(); q.pop();
            string builder = "";
            for (int i = from; i < n; i++) {
                builder += s[i];
                if (bag.count(builder) && dp[from] && !dp[i + 1])
                    dp[i + 1] = dp[from],
                    q.push(i + 1);
            }
        }
        return dp[n];
    }
};