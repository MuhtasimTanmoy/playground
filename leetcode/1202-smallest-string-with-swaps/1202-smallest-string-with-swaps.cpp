class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) 
            root[i] = i, rank[i] = 1;
    }
    
    int find(int x) {
        if (x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, 
                                   vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        for (vector<int> edge : pairs) {
            int source = edge[0];
            int destination = edge[1];
            // Perform the union of end points
            uf.unionSet(source, destination);
        }
        
        unordered_map<int, vector<int>> rootToComponent;
        for (int vertex = 0; vertex < s.size(); vertex++) {
            int root = uf.find(vertex);
            rootToComponent[root].push_back(vertex);
        }
        
        string smallestString(s.length(), ' ');
        for (auto component : rootToComponent) {
            vector<int> indices = component.second;
            
            vector<char> characters;
            for (int index : indices) characters.push_back(s[index]);
            sort(characters.begin(), characters.end());
            for (int index = 0; index < indices.size(); index++) 
                smallestString[indices[index]] = characters[index];
            
        }
        
        return smallestString;
    }
};