class UF {
    vector<int> parent, ranks;
public:
    UF(int n): parent(n), ranks(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto &rank: ranks) rank = 0;
    }
    
    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    
    void uni(int a, int b) {
        auto aRoot = find(a), bRoot = find(b);
        if (aRoot == bRoot) return;
        
        if (ranks[a] >= ranks[b]) {
            parent[bRoot] = aRoot;
            ranks[aRoot] += ranks[bRoot];
        } else {
            parent[aRoot] = bRoot;
            ranks[bRoot] += ranks[aRoot];
        }
    }
};

class Solution {
public:
    bool validPath(int n, 
                   vector<vector<int>>& edges, 
                   int source, 
                   int destination) {
        UF uf(n);
        for (auto edge: edges) uf.uni(edge[0], edge[1]);
        return uf.find(source) == uf.find(destination);
    }
};