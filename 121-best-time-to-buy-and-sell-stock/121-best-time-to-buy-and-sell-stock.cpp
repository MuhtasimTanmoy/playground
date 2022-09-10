class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, minSoFar = prices[0];
        for (auto price: prices) {
            res = max(price - minSoFar, res);
            minSoFar = min(minSoFar, price);
        }
        return res;
    }
};