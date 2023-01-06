class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) 
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset)  return;
        else if (rank[xset] < rank[yset]) parent[xset] = yset;
        else if (rank[xset] > rank[yset]) parent[yset] = xset;
        else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        UnionFind dsu(n + 1);
        for (int node = 1; node <= n; node++) 
            for (int neighbor : adj[node]) {
                if (dsu.find(node) == dsu.find(neighbor)) return false;
                dsu.union_set(adj[node][0], neighbor);
            }
        return true;
    }
};