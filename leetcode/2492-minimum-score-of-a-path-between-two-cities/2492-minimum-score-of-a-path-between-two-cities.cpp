class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> um;
        for (auto road: roads) {
            um[road[0]].push_back({road[1], road[2]});
            um[road[1]].push_back({road[0], road[2]});
        }
        
        unordered_set<int> visited;
        queue<int> q;
        q.push(1);
        
        int res = INT_MAX;
        while (q.size()) {
            auto top = q.front(); q.pop();
            
            if (visited.count(top)) continue;
            visited.insert(top);

            auto to = um[top];
            for (auto [dest, weight]: to) {
                q.push(dest);
                res = min(res, weight);
            }
        }
        return res;
    }
};