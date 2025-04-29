class Solution {
public:
    int findCircleNum(vector<vector<int>>& conn) {
        int province = 0, n = conn.size();
        unordered_set<int> visited;
        
        auto bfs = [&](int node) {
            vector<int> Q{node};
            visited.insert(node);
            while (Q.size()) {
                vector<int> temp;
                for (auto q: Q) {
                    for (int i = 0; i < n; i++) 
                        if (q != i && conn[q][i] && !visited.count(i)) 
                            temp.push_back(i),
                            visited.insert(i);
                }
                Q = temp;
            }
        };
        
        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            province++;
            bfs(i);
        }
        return province;
    }
};