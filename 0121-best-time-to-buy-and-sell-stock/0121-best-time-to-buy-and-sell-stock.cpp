class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, res = 0;
        for (auto price: prices) {
            minPrice = min(minPrice, price);
            res = max(res, price - minPrice);
        }
        return res;
    }
};