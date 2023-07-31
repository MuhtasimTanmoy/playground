class Solution {
public:
    double maxProbability(int n, 
                          vector<vector<int>>& edges, 
                          vector<double>& pro, 
                          int start, int end) {
        
        vector<vector<pair<int, double>>> g(n);
        for(int i = 0; i < edges.size(); i++) 
            g[edges[i][0]].push_back({edges[i][1], pro[i]}),
            g[edges[i][1]].push_back({edges[i][0], pro[i]});
        
        vector<int> seen(n, 0);
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});
        
        vector<double> mx(n, (double) 0.0);
        mx[start] = 1.0;
        
        while(q.size()) {
            auto top = q.top();
            q.pop();
            double proba = top.first;
            int node = top.second;
            if (!seen[node]) {
                seen[node]++;
                for(auto &to: g[node]) 
                    if (mx[to.first] < to.second*proba) 
                        mx[to.first] = to.second*proba,
						q.push({mx[to.first], to.first});
            }
        }
        return mx[end];
    }
};