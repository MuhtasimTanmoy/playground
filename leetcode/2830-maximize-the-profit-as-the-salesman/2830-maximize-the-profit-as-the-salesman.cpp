class Solution {
public:
//     int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
//         sort(offers.begin(), offers.end(), [](auto l, auto r) {
//             auto is_eq_start = l.front() == r.front();
//             return is_eq_start ? l[1] < r[1] : l.front() < r.front();            
//         });
        
//         unordered_map<string, int> dp;
//         auto gen_key = [](int a, int b) {
//             return to_string(a) + "-" + to_string(b);
//         };
        
//         int len = offers.size();
//         function<int(int, int)> go = [&](auto i, auto upto) {
//             if (i == len) return 0;
            
//             auto key = gen_key(i, upto);
//             if (dp.count(key)) return dp[key];
            
//             auto res = go(i + 1, upto); // dont_take
            
//             auto from = offers[i].front(), to = offers[i][1], price = offers[i].back();
//             if (from > upto) 
//                 res = max(res, price + go(i + 1, to));
//             return dp[key] = res;
//         };
        
//         return go(0, -1);
//     }
    
    
//     int dfs(vector<vector<int>>& e, int i) {
//         if (i >= e.size()) return 0;
//         if (dp[i] != -1) return dp[i];
        
//         auto j = upper_bound(begin(e) + i, end(e), e[i][1], [](int t, const vector<int> &v) {return v[0] > t;}) - begin(e);
//         return dp[i] = max(e[i][2] + dfs(e, j), dfs(e, i + 1));
//     }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        auto dp = vector<int>(offers.size(), -1);
        
        function<int(int)> go = [&](auto i) {
            if (i == offers.size()) return 0;
            if (dp[i] != -1) return dp[i];
            auto res = go(i + 1);
            
            auto from = offers[i].front(), to = offers[i][1], gold = offers[i].back();
            auto next = upper_bound(offers.begin() + i, offers.end(), to, 
                                    [](int t, const vector<int>& v) {
                                        return v.front() > t; 
                                    }) - offers.begin();
            
            res = max(res, gold + go(next));
            return dp[i] = res;
        };
        
        return go(0);
    }
};