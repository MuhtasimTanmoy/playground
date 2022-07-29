// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(), coins.end(), greater<int>());
//         int res = INT_MAX;
//         function<void(int, int, int)> calculate = [&](int index, int amount, int count) {
//             if (amount < 0 ) return;
//             if (index >= size(coins)) return;
//             if (!amount) {  res = min(res, count); return; }
//             calculate(index, amount - coins[index], count + 1);
//             calculate(index + 1,  amount, count);
//         };
//         calculate(0, amount, 0);
//         return res == INT_MAX ? -1 : res;
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (auto coin: coins) {
                if (i - coin < 0) continue;
                if (dp[i - coin] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};