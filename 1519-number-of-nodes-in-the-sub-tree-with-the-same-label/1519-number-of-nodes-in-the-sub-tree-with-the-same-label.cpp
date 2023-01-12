// class Solution {
//     unordered_map<int, vector<int>> g;
// public:
//     vector<int> countSubTrees(int n, 
//                               vector<vector<int>>& edges, 
//                               string labels) {
//         for (auto e: edges) {
//             g[e[0]].push_back(e[1]);
//             g[e[1]].push_back(e[0]);
//         }
        
//         vector<int> res(n, 0);
//         function<int(int, char)> traverse = [&](auto node, auto parent) {
//             int count = 0;
//             for (auto l: g[node]) {
//                 // if (res[node] != 0) 
//                     count += traverse(l, parent);
//             }
//             return count + (parent == labels[node] ? 1: 0);
//         };
        
//         for (int i = 0; i < n; i++) res[i] = traverse(i, labels[i]);
//         return res;
//     }
// };


class Solution {
public:
    vector<int> countSubTrees(int n, 
                              vector<vector<int>>& edges, 
                              string labels) {        
        response.resize(n);
        node2edges.resize(n);
        Labels = &labels;
        for (const auto& edge: edges) {
            node2edges[edge[0]].push_back(edge[1]);
            node2edges[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        return std::move(response);
    }
private:
    void dfs(int nodeId, int parentNodeId) {
        int nodeLabelId = Labels->at(nodeId) - 'a';
        int before = labelCount[nodeLabelId];
        ++labelCount[nodeLabelId];
        for (const auto& nextNodeId: node2edges[nodeId]) {            
            if (nextNodeId == parentNodeId) 
                continue;
            dfs(nextNodeId, nodeId);
        }
        response[nodeId] = labelCount[nodeLabelId] - before;
    }
    
private:
    vector<int> response;
    vector<vector<int>> node2edges;
    string *Labels;
    int nodeLabelId = 0;
    int labelCount[26];
};