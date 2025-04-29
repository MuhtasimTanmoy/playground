// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& R) {
//         unordered_map<int, vector<pair<int, int>>> G;
//         for (auto r: R) {
//             auto from = r.front(), to = r[1], time = r.back();
//             G[from].push_back({to, time});
//             G[to].push_back({from, time});
//         }

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, 0});

//         unordered_set<int> visisted;
//         int res = 0, track_min = INT_MAX;
//         while (pq.size()) {
//             auto [cost, node] = pq.top(); pq.pop();
//             visisted.insert(node);

//             if (node == n - 1) {
//                 if (cost < track_min) { res = 1; track_min = cost; }
//                 else if (cost == track_min) res++;
//                 else break;
//             }

//             for (auto to: G[node]) {
//                 auto [to_node, to_cost] = to;
//                 if (visisted.count(to_node)) continue;
//                 pq.push({cost + to_cost, to_node});
//             }
//         }
//         return res;
//     }
// };



class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        vector<long> time(n, 0), cnt(n, 1);
        for (auto &road : roads) {
            auto from = road[0], to = road[1], weight = road[2];
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }
        
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
        pq.push({0, 0});
        
        while (pq.size()) {
            auto [dist, i] = pq.top(); pq.pop();
            for (auto [j, t] : graph[i]) {
                if (time[j] == 0 || time[j] >= dist + t) {
                    if (time[j] == dist + t)
                        cnt[j] = (cnt[j] + cnt[i]) % 1000000007;
                    else {
                        time[j] = dist + t;
                        cnt[j] = cnt[i];
                        pq.push({time[j], j});
                    }
                }
            }
        }
        return cnt[n - 1];
        
    }
};