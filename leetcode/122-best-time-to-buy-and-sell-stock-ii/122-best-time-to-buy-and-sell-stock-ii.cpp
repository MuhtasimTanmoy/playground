class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int currentGain = 0;
        for (int i = 1; i < prices.size(); i++) {
            auto gain = prices[i] - prices[i-1];
            if ( gain > 0 ) res += gain;
        }
        return res;
    }
};