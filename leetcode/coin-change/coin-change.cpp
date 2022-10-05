class Solution {
    
    // GETS TLE
    
    // int minStep = INT_MAX;
    // void minChange(vector<int>& coins, int amount, int step) {
    //     for(auto coin: coins) {
    //         if (amount - coin == 0) {
    //             minStep = min(minStep, step);
    //             return;
    //         }
    //         if (amount - coin < 0 ) continue;
    //         minChange(coins, amount - coin, step + 1);
    //     }
    // }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end(), greater<int>());
        // minChange(coins, amount, 1);
        // return minStep == INT_MAX ? -1 : minStep;
        
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(auto coin: coins)
            for(int i = coin; i <= amount; i++) {
                if (dp[i-coin] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};