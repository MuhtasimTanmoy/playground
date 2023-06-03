class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n, vector<int>{});
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            auto top = manager[i];
            g[top].push_back(i);
        }
        function<int(int)> go = [&](auto i) {
            int cost = 0;
            for (auto to: g[i]) 
                cost = max(cost, go(to));
            return informTime[i] + cost;
        };
        return go(headID);
    }
};