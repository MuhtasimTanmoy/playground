// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         unordered_map<int, vector<pair<int, int>>> g;
//         for(auto flight: flights) {
//             auto from = flight[0], to = flight[1], price = flight[2];
//             g[from].push_back({to, price});
//         }
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, >
        
//     }
// };

// typedef tuple<int,int,int> ti;
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         vector <vector<pair<int,int>>> vp(n);
//         for(const auto& f: flights) vp[f[0]].emplace_back(f[1], f[2]);
        
//         priority_queue<ti, vector<ti>, greater<ti>> pq;
//         pq.emplace(0, src, K + 1);
        
//         while(!pq.empty()) {
//             auto [cost, u, stops] = pq.top();
//             pq.pop();
            
//             if (u == dst) return cost;
//             if (!stops) continue;
//             for (auto to: vp[u]) {
//                 auto [v,w] = to;
//                 pq.emplace(cost + w, v, stops - 1);
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    template<typename T_a3, typename T_vector>
    void bellman_ford(T_a3 &g, T_vector &dist, int src, int mx_edges) {
        dist[src] = 0;
        for (int i = 0; i <= mx_edges; i++) {
            T_vector ndist = dist;
            for (auto x : g) {
                auto [from, to, cost] = x;
                ndist[to] = min(ndist[to], dist[from] + cost);
            }
            dist = ndist;
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<array<int, 3>> g;
        vector<int> cost(n, 1e9);
        for (auto f : flights) g.push_back({f[0], f[1], f[2]});
        bellman_ford(g, cost, src, k);
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};