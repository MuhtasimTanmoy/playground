// Wrong Approach
/*
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        sort(stones.begin(), stones.end(), [&](const vector<int>& a, const vector<int>& b) { return (a[0] + a[1]) > (b[0] + b[1]); });
        int res = 0;
        unordered_set<int> xAxis, yAxis;
        for (auto coordinate: stones) {
            auto x = coordinate[0], y = coordinate[1];
            if (xAxis.count(x) || yAxis.count(y)) res++;
            xAxis.insert(x);
            yAxis.insert(y);
        }
        return res;
    }
};
*/

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) root[i] = i, rank[i];
        cnt = sz;
    }

    // path compression
    int find(int x) {
        if (x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    // rank based
    void unionSetRankBased(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) root[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) root[rootX] = rootY;
            else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            cnt--;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int disjointCount() {
        return cnt;
    }

private:
    vector<int> root, rank;
    int cnt;
};

   
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = (int) stones.size();
        UnionFind d = UnionFind(n);
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) 
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) 
                    d.unionSetRankBased(i, j);

        return n - d.disjointCount();
    }
};