class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& cons) {
        if (cons.size() < n - 1) return -1;
        
        vector<vector<int>> g(n, vector<int>{});
        for (auto c: cons) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        
        unordered_set<int> visited;
        function<void(int)> dfs = [&](auto i) {
            visited.insert(i);
            auto to = g[i];
            for (auto t: to) 
                if (visited.count(t) == 0) dfs(t);
        };
        
        int connected_comps = 0;
        for(int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            connected_comps++;
            dfs(i);
        }
        
        return connected_comps - 1;
    }
};