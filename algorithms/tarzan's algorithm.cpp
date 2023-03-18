class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> firstTime(n), minTime(n);
        int visitedCount = 0;
        vector<bool> visited(n, false);
        
        for(auto connection: connections) {
            int from = connection[0];
            int to = connection[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        vector<vector<int>> result;
        int time = 0;
        function<void(int, int)> dfs = [&](int node, int parent) {
            visited[node] = true;
            firstTime[node] = minTime[node] = time++;
            
            for(auto &edge: graph[node]) {
                if (edge == parent) continue;
                if (!visited[edge]) dfs(edge, node);
                
                minTime[node] = min(minTime[edge], minTime[node]);
                if(firstTime[node] < minTime[edge]) result.push_back({node, edge});
            }
        };
        
        dfs(0, -1);        
        return result;
    }
};

// another approach

//         function<void(int, vector<int>, vector<int>&)> dfs = 
//             [&](int node, vector<int> ignore, vector<int>& visited) {
//             visited[node] = true;
//             visitedCount++;
//             for(auto edge: graph[node]) {
//                 if(visited[edge]) continue;
//                 if (ignore[0] == node && ignore[1] == edge) continue;
//                 if (ignore[1] == node && ignore[0] == edge) continue;
//                 dfs(edge, ignore, visited);
//             }
//         };
        
//         vector<vector<int>> result;
//         for(int i = 0 ; i < size(connections); i++) {
//             visitedCount = 0;
//             vector<int> visited(n, 0);
//             dfs(0, connections[i], visited);
//             if (visitedCount < n) result.push_back(connections[i]);
//         }