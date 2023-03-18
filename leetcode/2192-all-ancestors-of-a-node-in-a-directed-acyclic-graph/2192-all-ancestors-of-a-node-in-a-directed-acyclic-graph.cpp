class Solution {
public:
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
//         unordered_map<int,vector<int>> node_to_parent;
        
//         for (auto edge: edges)
//             node_to_parent[edge[1]].push_back(edge[0]);
        
//         vector<vector<int>> res(n, vector<int>{});
//         for (auto [node, p]: node_to_parent) {
//             vector<int> pq(p.begin(), p.end());
//             while (pq.size()) {
//                 auto now = pq.back(); pq.pop_back();
//                 res[node].push_back(now);
//                 if (node_to_parent.count(now))
//                     for (auto gp: node_to_parent[now]) 
//                         pq.push_back(gp);
//             }
//         }
        
//         for (auto &elem: res) {
//             auto order = set<int>(elem.begin(), elem.end());
//             elem = vector<int>(order.begin(), order.end());
//         }
        
//         return res;
//     }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), al(n);
        function<void(int, int)> dfs = [&](int i, int anc){
            for (auto j : al[i])
                if (res[j].empty() || res[j].back() != anc) {
                    res[j].push_back(anc);
                    dfs(j, anc);    
                }
        };
        for (auto &e: edges)
            al[e[0]].push_back(e[1]);
        for (int i = 0; i < n; ++i)
            dfs(i, i);
        return res;    
    }
};