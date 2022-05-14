// class Solution {
    
//     bool visited[ 100 + 1];
//     int result = 0;
    
// //     void dfs(vector<vector<pair<int, int>>> network, 
// //              pair<int, int> node, 
// //              int weightSoFar) {
        
// //         weightSoFar += node.second;
// //         result = max(result, weightSoFar);
                     
// //         visited[node.first] = true;
        
// //         auto elements = network[node.first];
// //         for(int i = 0; i < size(elements); i++) {
// //             if (!visited[elements[i].first]) 
// //                  dfs(network, elements[i], weightSoFar);   
// //         }
// //     }
    
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
//         vector<vector<pair<int, int>>> network( n + 1 );
//         for(auto elem: times)
//             network[elem[0]].push_back({elem[1], elem[2]});
        
//         dfs(network, {k, 0}, 0);
//         for(int i = 1; i <= n; i++) 
//             if (visited[i] == false) 
//                 return -1;
        
//         return result;
//     }
// };

// It cant be solved using dfs

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        auto comp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.second > b.second;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        
        vector<vector<int>> rel(n, vector<int>(n, -1));
        
        for (auto &time: times)
            rel[time[0] - 1][time[1] - 1] = time[2];
        
        vector<int> visit(n, 0);
        que.push({k-1, 0});
        
        int sz = n;
        
        while (que.size()) {
            
            auto now = que.top();
            
            que.pop();
            
            if (visit[now.first]) 
                continue;
            
            visit[now.first] = 1;
            
            if (!--sz) 
                return now.second;
            
            auto id = now.first, val = now.second;
            
            for (int i = 0; i < n; ++i) {
                
                if (rel[id][i] != -1) 
                    que.push({i, val + rel[id][i]});
                
            }
        }
        
        return -1;
    }
};