// class Solution {
// public:
//     int minimumTime(int n, vector<vector<int>>& r, vector<int>& t) {
//         vector<vector<int>> wave(n + 1);
        
//         vector<int> indegree(n + 1, 0);
//         for (auto dir: r) {
//             auto from = dir.front(), to = dir.back();
//             wave[from].push_back(to);
//             indegree[to]++;
//         }
        
//         unordered_set<int> q, processed;
//         for (auto i = 1; i <= n; i++)
//             if (!indegree[i])
//                 q.insert(i);
        
//         int res = 0;
//         while (q.size()) {
//             unordered_set<int> temp;
//             int max_in_this_tier = INT_MIN;
//             for (auto item: q) {
//                 processed.insert(item);
//                 max_in_this_tier = max(max_in_this_tier, t[item - 1]);
//                 for (auto to: wave[item])
//                     if (!processed.count(to))
//                         temp.insert(to);
//             }
            
//             cout<<max_in_this_tier<<endl;
//             res += max_in_this_tier;
//             q = temp;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n);
        vector<vector<int>> graph(n, vector<int>());
        for (auto& edge : relations) {
            auto prev = edge[0] - 1, next = edge[1] - 1;
            graph[prev].push_back(next);
            inDegree[next]++;
        }
        
        vector<int> dist(n);
        queue<int> q;
        for (int u = 0; u < n; ++u) 
            if (inDegree[u] == 0) 
                q.push(u), dist[u] = time[u];
        
        while (q.size()) {
            auto u = q.front(); q.pop();
            for (int v : graph[u]) {
                dist[v] = max(dist[v], dist[u] + time[v]);
                if (--inDegree[v] == 0) 
                    q.push(v);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};