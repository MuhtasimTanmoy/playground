class Solution {
public:
//     int tallestBillboard(vector<int>& rods, int res = 0) {
//         auto gen_key = [](int a, int b, int c) {
//             return to_string(a) + "-" + to_string(b) + to_string(c);
//         };
//         unordered_set<string> c;
//         function<void(int, int, int)> go = [&](auto i, auto l, auto r) {
            
//             if (l == r) res = max(l, res);
//             if (i == rods.size()) return;
            
//             auto key = gen_key(i, l, r);
//             if (c.count(key)) return;
//             c.insert(key);
            
//             go(i + 1, l + rods[i], r);
//             go(i + 1, l, r + rods[i]);
//             go(i + 1, l, r);
//         };
//         go(0, 0, 0);
//         return res;
//     }
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int x : rods) {
            unordered_map<int, int> cur(dp);
            for (auto it: cur) {
                int d = it.first;
                dp[d + x] = max(dp[d + x],cur[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], cur[d] + min(d, x));
            }
        }
        return dp[0];
    }
};