class Solution {
public:
    int timeRequiredToBuy(vector<int>& ts, int k) {
        int res = 0;
        for (auto i = 0; i < ts.size(); i++) 
            if (i <= k) res += min(ts[k], ts[i]);
            else res += min(ts[k] - 1, ts[i]);
        return res;
    }
};