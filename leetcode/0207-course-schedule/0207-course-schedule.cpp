class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> g(n);
        
        vector<int> indegree(n);
        int node_count = 0;
        for (auto prereq: prereqs) {
            auto from = prereq[1], to = prereq[0];
            g[from].push_back(to);
            indegree[to]++;
        }
        
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++)
            if (!indegree[i]) 
                q.push(i);
        
        while (q.size()) {
            auto top = q.front(); q.pop();
            node_count++;
            for (auto to: g[top])
                if (--indegree[to] == 0)
                    q.push(to);
        }
        return node_count == n;
    }
};