class Solution {
public:
//     int longestIdealString(string s, int k) {
//         unordered_map<string, int> cache;
        
//         auto key = [](int a, char b) {
//             return to_string(a) + "-" + b;
//         };
        
//         function<int(int, char)> go = [&](auto i, auto prev) {
//             if (i == s.size()) return 0;
//             auto ke = key(i, prev);
//             if (cache.count(ke)) return cache[ke];
            
//             int pick = 0;
//             if (abs(s[i] - prev) <= k || prev == '#') 
//                 pick = 1 + go(i + 1, s[i]);
//             pick = max(pick, go(i + 1, prev));
//             return cache[ke] = pick;
//         };
//         return go(0, '#');
//     }
    
    int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for (auto& i : s) {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }
};