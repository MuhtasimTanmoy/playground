class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vector<int> indegree(g.size());
        vector<vector<int>> rev(g.size());
        for (int i = 0; i < g.size(); i++) 
            for (auto node: g[i])
                indegree[i]++,
                rev[node].push_back(i);
        
        queue<int> q;
        for (auto i = 0; i < g.size(); i++) if (!indegree[i]) q.push(i);
        
        vector<int> res;
        while (q.size()) {
            auto top = q.front(); q.pop();
            res.push_back(top);
            for (auto from: rev[top])
                if (--indegree[from] == 0) q.push(from);
        }
        sort(res.begin(), res.end());
        return res;
    }
};