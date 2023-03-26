class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> g;
        for (auto edge: edges)
            g[edge[0]].push_back(edge[1]),
            g[edge[1]].push_back(edge[0]);
        
        unordered_set<int> visited;
        int visited_count = 0;
        
        function<void(int)> go = [&](auto i) {
            if (visited.count(i)) return;
            
            visited.insert(i);
            visited_count++;
            
            auto to = g[i];
            for (auto t: to) go(t);
        };
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            go(i);
            res.push_back(visited_count);
            visited_count = 0;
        }
        
        long long count = 0, sum = 0;
        for (int i = 1; i < res.size(); i++) {
            sum += res[i-1];
            count += sum * res[i];
        }
        
        return count;
    }
};