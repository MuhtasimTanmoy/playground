class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> g;
        for (auto p: pairs)
            g[p[0]].push_back(p[1]),
            g[p[1]].push_back(p[0]);
        
        int head = -1;
        for (auto now: g) 
            if (now.second.size() == 1) {
                head = now.first;
                break;
            }
        
        vector<int> res;
        unordered_set<int> visited;
        function<void(int)> go = [&](auto i) {
            if (visited.count(i)) return;
            res.push_back(i);
            visited.insert(i);
            for (auto to: g[i]) go(to);
        };
        go(head);
        return res;
    }
};