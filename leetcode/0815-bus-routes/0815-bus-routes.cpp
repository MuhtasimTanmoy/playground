/*
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        unordered_map<int, vector<int>> g;
        for (auto i = 0; i < routes.size(); i++)
            for (auto now: routes[i])
                g[now].push_back(i);
        
        vector<int> q {s};
        unordered_set<int> seen; seen.insert(s);
        if (s == t) return 0;
        int res = 1;
        while (q.size()) {
            vector<int> temp;
            for (auto to: q) 
                for (auto i: g[to]) 
                    for (auto now: routes[i]) {
                        if (now == t) return res;
                        if (!seen.count(now)) 
                            temp.push_back(now),
                            seen.insert(now);
                    }
            q = temp, res++;
        }
        return -1;
    }
};
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, 
                              int S, int T) {
        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        
        queue<pair<int, int>> bfs;
        bfs.push({S, 0});
        
        unordered_set<int> seen = {S};
        while (bfs.size()) {
            int stop = bfs.front().first, bus = bfs.front().second;
            bfs.pop();
            if (stop == T)
                return bus;
            for (int i : to_routes[stop]) {
                for (int j : routes[i]) {
                    if (seen.find(j) == seen.end()) {
                        seen.insert(j);
                        bfs.push({j, bus + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};