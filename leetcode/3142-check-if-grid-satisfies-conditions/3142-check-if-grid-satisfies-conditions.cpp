class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& g) {
        int prev = -1;
        for (auto i = 0; i < g.back().size(); i++) {
            int now = g[0][i];
            if (now == prev) return false;
            prev = now;
            for (auto j = 1; j < g.size(); j++)
                if (g[j][i] != now) 
                    return false;
        }
        return true;
    }
};