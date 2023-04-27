// https://leetcode.com/problems/closest-dessert-cost/discuss/1086211/C%2B%2B-Backtracking
// Couldn't solve
class Solution {
public:
    void dp(vector<int>& tC, int i, int cost, int t, int &best, int max_top = 2) {
        if (cost >= t || i >= tC.size()) {
            if (abs(cost - t) < abs(best - t))
                best = cost;
            else if (abs(best - t) == abs(cost - t))
                best = min(best, cost);            
        }
        else
            for (auto j = 0; j <= max_top; ++j)
                dp(tC, i + 1, cost + j * tC[i], t, best);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int best = INT_MAX;
        for (auto base : baseCosts)
            dp(toppingCosts, 0, base, target, best);
        return best;
    }
};