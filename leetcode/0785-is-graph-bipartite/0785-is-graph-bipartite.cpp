class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        queue<int> q;     
        for (int i = 0; i < n; i++) {
            if (colors[i]) continue;
            q.push(i); colors[i] = 1;
            while (q.size()) {
                auto top = q.front(); q.pop();
                for (auto to: graph[top]) 
                    if (colors[to] == 0) 
                        colors[to] = -colors[top], q.push(to);
                    else
                        if (colors[to] == colors[top]) return false;
            }
        }
        return true;
    }
};