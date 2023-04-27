class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        for (auto e: prereq) {
            auto take = e[0], pre = e[1];
            g[pre].push_back(take),
            indegree[take]++;
        }
        queue<int> q;
        for (auto i = 0; i < n; i++) if (!indegree[i]) q.push(i);
        vector<int> res;
        while (q.size()) {
            auto course = q.front(); q.pop();
            res.push_back(course);
            for (auto to: g[course]) if (--indegree[to] == 0) q.push(to);
        }
        return res.size() == n ? res: vector<int>{};
    }
};