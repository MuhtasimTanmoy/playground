class Solution {
public:
    int maxProfit(vector<int>& P) {
        int res = 0;
        for (auto i = 1; i < P.size(); i++) 
            res += max(P[i] - P[i-1], 0);
        return res;
    }
};