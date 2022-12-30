/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> l(prices.size(), 0), r(prices.size() + 1, 0);
        int minL = prices[0], maxR = prices[prices.size() - 1];
        
        for (int i = 1; i < prices.size(); i++) {
            minL = min(prices[i], minL);
            l[i] = max(prices[i] - minL, l[i-1]);
        }
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            r[i] = max(maxR - prices[i], r[i+1]);
            maxR = max(prices[i], maxR);
        }
        
        int res = INT_MIN;
        for (int i = 0; i < prices.size(); i++) res = max(res, l[i] + r[i+1]);
        return res;
    }
};
*/
class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MAX, t2Cost = INT_MAX;
    int t1Profit = 0, t2Profit = 0;
    for (int price : prices) {
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
    }
    return t2Profit;
  }
};