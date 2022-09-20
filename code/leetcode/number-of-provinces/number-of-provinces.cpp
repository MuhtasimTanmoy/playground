class UnionFind {
    public:
    
    UnionFind(int x): root(x), rank(x), count(x) {
        for ( int i = 0; i < x; i++ ) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x) {
        if ( x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    
    void unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        
        if (rootA == rootB) return;
        
        if (rank[rootA] > rank[rootB]) {
            root[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            root[rootA] = rootB;
        } else {
            root[rootB] = rootA;
            rank[rootA] += 1;
        }
        count--;
    }
    
    
    
    int getCount() { return count; }
    
    private:
    vector<int> root;
    vector<int> rank;
    int count;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) return 0;
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (isConnected[i][j] == 1) uf.unionSet(i, j);
        return uf.getCount();
    }
};