class Solution {
    vector<int> color;
    bool isBiparatite = true;   
    
    void dfs(vector<vector<int>>& graph, int index) {
        auto parent = graph[index];
        
        for(auto child: parent) {
            if(color[child] == -1) {
                color[child] = color[index] ^ 1;
                dfs(graph, child);
            } else 
                if (color[child] == color[index]) {
                    isBiparatite = false;
                    break;
                }
        }
    }
    
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = size(graph);
        color = vector<int>(n, -1);

        for(int i = 0; i < n; i++ ) 
            if (color[i] == -1) {
                color[i] = 0;
                dfs(graph, i);
            }
        
        return isBiparatite;
    }
};