class Solution {
    unordered_map<int, vector<int>> go;
    vector<bool> hasAppleG, visited;
    int pathCost = 0;
    bool traverse(int id) {
        auto containsApple = hasAppleG[id];
        bool leafHasApple = false;
        for (auto dest: go[id]) {
            if (visited[dest]) continue;
            visited[dest] = true;
            pathCost++;
            auto thisLeafHasApple =  traverse(dest);
            leafHasApple |= thisLeafHasApple;
            pathCost = thisLeafHasApple ? pathCost + 1: pathCost - 1;
        }
        return leafHasApple || containsApple;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        hasAppleG = hasApple;
        visited = vector<bool>(n, false);
        visited[0] = true;
        for (auto edge: edges) {
            go[edge[0]].push_back(edge[1]);
            go[edge[1]].push_back(edge[0]);
        }
        traverse(0);
        return pathCost;
    }
};