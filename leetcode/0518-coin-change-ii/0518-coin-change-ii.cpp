class Solution {
public:
//     int change(int amount, vector<int>& coins) {
//         unordered_set<string> bag;
//         function<int(int, string)> go = [&](int left, string s) {
//             if (left < 0) return 0;
//             if (left == 0) {
//                 sort(s.begin(), s.end());
//                 return bag.insert(s).second ? 1: 0;
//             }
            
//             int ways = 0;
//             for (auto coin: coins) {
//                 s += to_string(coin);
//                 ways += go(left - coin, s);
//             }
//             return ways;
//         };
//         return go(amount, "");
//     }
    
//     int change(int amount, vector<int>& coins) {
//         auto gen_key = [](auto l, auto ... r) { 
//             return (to_string(l) + ... + ( "-" + to_string(r))); 
//         };
//         unordered_map<string,int> um;
//         function<int(int, int)> go = [&](auto i, auto left) {
//             if (left == 0) return 1;
//             if (i == coins.size() || left < 0) return 0;
            
//             auto key = gen_key(i, left);
//             if (um.count(key)) return um[key];
            
//             int ways = go(i + 1, left);
//             ways += go(i, left - coins[i]);
//             return um[key] = ways;
//         };
//         return go(0, amount);
//     }
    
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (auto coin: coins)
            for (int i = 1; i <= amount; i++)
                if (i - coin >= 0)
                    dp[i] += dp[i - coin];
        
        return dp[amount];
    }
};