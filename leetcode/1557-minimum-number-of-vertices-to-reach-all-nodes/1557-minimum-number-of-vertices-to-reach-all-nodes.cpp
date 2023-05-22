class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto edge: edges) {
            auto from = edge[0], to = edge[1];
            indegree[to]++;
        }
        vector<int> res;
        for (int  i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0)
                res.push_back(i);
        return res;
    }
};