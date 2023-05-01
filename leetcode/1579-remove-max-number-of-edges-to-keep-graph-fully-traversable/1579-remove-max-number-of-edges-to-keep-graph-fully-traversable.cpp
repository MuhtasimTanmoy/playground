class UnionFind {
    int n;
    vector<int> parent, rank;
public:
    UnionFind(int n): n(n) {
        for (int i = 0; i <= n; i++) parent.push_back(i);
        for (int i = 0; i <= n; i++) rank.push_back(1);
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    int make_union(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        
        if (rank[x] > rank[y]) parent[y] = x, rank[x] += rank[y];
        else parent[x] = y, rank[y] += rank[x];
        
        n--;
        return 1;
    }
    
    bool is_connected() {
        cout<<n<<endl;
        return n == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind a(n), b(n);
        
        int edges_cnt = 0;
        for (auto edge: edges)
            if (edge[0] == 3)
                edges_cnt += a.make_union(edge[1], edge[2]) | b.make_union(edge[1], edge[2]);
        
         for (auto edge: edges)
            if (edge[0] == 1) edges_cnt += a.make_union(edge[1], edge[2]);
            else if (edge[0] == 2) edges_cnt += b.make_union(edge[1], edge[2]);
        
        if (a.is_connected() && b.is_connected()) return edges.size() - edges_cnt;
        return -1;
    }
};