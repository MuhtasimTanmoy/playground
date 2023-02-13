class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads, int res = 0) {
        vector<unordered_set<int>> g(n);
        for (auto r: roads) 
            g[r[0]].insert(r[1]),
            g[r[1]].insert(r[0]);
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int total = g[i].size() + g[j].size() - g[i].count(j);
                res = max(res, total);
            }
        return res;
    }
};