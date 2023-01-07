class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (stk.size() &&  prices[i] < stk.top()) stk.pop();
            auto cache = prices[i];
            if (stk.size()) prices[i] -= stk.top();
            stk.push(cache);
        }
        return prices;
    }
};