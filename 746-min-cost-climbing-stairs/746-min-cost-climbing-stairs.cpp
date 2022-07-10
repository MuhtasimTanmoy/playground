class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int rem1 = 0, rem2 = 0;
        for (int i = 2; i <= size(cost); i++) {
            auto now = min(rem1 + cost[i-1], rem2 + cost[i-2]);
            rem2 = rem1;
            rem1 = now;
        }
        return rem1;
    }
};