class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = prices.size();
        int cont = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] == prices[i] + 1) {
                cont += 1;
                res += cont;
            } else cont = 0;
        }
        return res;
    }
};