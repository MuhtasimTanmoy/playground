// My dumb slow solution
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> g;
        for (auto edge: edges) {
            auto from = edge[0], to = edge[1];
            g[from].push_back(to);
            g[to].push_back(from);
        }
        auto node_present = g.size();
        for (int i = edges.size() - 1; i >= 0; i--) {
            auto black_listed = edges[i];
            auto find = node_present;
            unordered_set<int> visited;
            auto is_whitelisted = [&](int from, int to) {
                if (black_listed[0] == from && black_listed[1] == to) return false;
                if (black_listed[1] == from && black_listed[0] == to) return false;
                return true;
            };
            function<void(int)> go = [&](int node) {
                visited.insert(node);
                find--;
                for (auto to: g[node]) 
                    if (!visited.count(to) && is_whitelisted(node, to))
                        go(to);
            };
            go(1);
            if (find == 0) return black_listed;
        }
        throw "error";
    }
};


// Copied from discussions
// class Solution {
//     vector<int> parent;
//     int find_set(int v) {
//         if (v == parent[v]) return v;
//         return parent[v] = find_set(parent[v]);
//     }
//     bool union_set(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if (a == b) return true;
//         parent[b] = a;
//         return false;
//     }
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         for (int i = 0; i <= edges.size(); i++) parent.push_back(i);
//         for (auto &e :edges)
//              if (union_set(e[0], e[1]))
//                  return {e[0], e[1]};
//         return {-1, -1};
//     }
// };