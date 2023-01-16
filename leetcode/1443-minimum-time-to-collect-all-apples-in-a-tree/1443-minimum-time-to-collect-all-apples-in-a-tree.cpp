class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        auto visited = vector<bool>(n, false); visited[0] = true;
        for (auto e: edges) go[e[0]].push_back(e[1]), go[e[1]].push_back(e[0]);
        function<bool(int)> traverse = [&](auto id) {
            auto containsApple = hasApple[id];
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
        };
        traverse(0);
        return pathCost;
    }
private:
    unordered_map<int, vector<int>> go;
    int pathCost = 0;
};