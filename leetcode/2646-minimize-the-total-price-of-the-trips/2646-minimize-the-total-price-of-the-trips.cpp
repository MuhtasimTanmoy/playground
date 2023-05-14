class Solution {
    int demand[100];
    vector<int> adj[100];
public:
    int isInPath(int u, int dest, int p = -1) {
        if (u == dest) {
            demand[dest]++;
            return 1;
        }
        for (auto v: adj[u]) {
            if (v == p) continue;
            if (isInPath(v, dest, u)) {
                demand[u]++;
                return 1;
            }
        } 
        return 0;
    }

    pair<int,int> minNonAdjecentPath(int u, int p, vector<int>& price) {
        auto take = (price[u] / 2) * demand[u],
             dont_take = price[u] * demand[u];
        for (auto v: adj[u]) {
            if (v == p) continue;
            auto leaf = minNonAdjecentPath(v, u, price);
            dont_take += min(leaf.first, leaf.second);
            take += leaf.second;
        }
        return {take, dont_take};
    }
    
    int minimumTotalPrice(int n, 
                          vector<vector<int>>& edges, 
                          vector<int>& price, 
                          vector<vector<int>>& trips) {
        memset(demand,0, sizeof demand);
        for (auto i = 0; i < n; i++) adj[i].clear();
        for (auto edge: edges) {
            auto u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (auto trip: trips) {
            auto u = trip[0], v = trip[1];
            isInPath(u, v);
        }
        auto ans = minNonAdjecentPath(0, -1, price);
        return min(ans.first, ans.second);
    }
};