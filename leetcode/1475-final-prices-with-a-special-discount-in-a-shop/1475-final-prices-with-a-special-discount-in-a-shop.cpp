class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.begin(), prices.end()), stk;
        for (int i = 0; i < prices.size(); i++) {
            while (stk.size() && prices[i] <= prices[stk.back()]) {
                auto target_index = stk.back(); stk.pop_back();
                res[target_index] -= prices[i];
            }
            stk.push_back(i);
        }
        return res;
    }
};