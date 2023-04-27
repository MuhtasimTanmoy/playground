class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>&e , vector<int>& r) {
        unordered_set<int> s(begin(r),end(r));
        vector<vector<int>> graph(n);
        for(auto i: e) graph[i[0]].push_back(i[1]) , graph[i[1]].push_back(i[0]);
        
        queue<int> q;
        vector<bool> seen(n);
        
        int cnt = 0;
        q.push(0);
        seen[0] = true;
        
        while (q.size()) {
            auto node = q.front(); q.pop();
            if (s.count(node)) continue;
            cnt++;
            for (auto j: graph[node])
                if (!seen[j]) seen[j] = true, q.push(j);
        }
        return cnt;
    }
};