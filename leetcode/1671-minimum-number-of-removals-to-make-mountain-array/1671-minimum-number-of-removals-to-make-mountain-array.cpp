class Solution {
public:
    int minimumMountainRemovals(vector<int>& n) {
        int res = INT_MAX, sz = n.size();
        vector<int> l, r, dp(sz);
        for (int i = 0; i < sz; ++i) {
            auto it = lower_bound(begin(l), end(l), n[i]);
            if (it == l.end()) l.push_back(n[i]); else *it = n[i];
            dp[i] = l.size();
        }
        for (int i = n.size() - 1; i > 0; --i) {
            auto it = lower_bound(begin(r), end(r), n[i]);
            if (it == r.end()) r.push_back(n[i]); else *it = n[i];
            if (dp[i] > 1 && r.size() > 1)
                res = min(res, sz - dp[i] - (int) r.size() + 1);
        }
        return res;
    }
};