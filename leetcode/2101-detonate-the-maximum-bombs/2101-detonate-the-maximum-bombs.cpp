class Solution {
public:
    int maximumDetonation(vector<vector<int>>& b) {
        auto distance = [](int px, int py, int qx, int qy) -> long long {
            long long dis_x = abs(px - qx), dis_y = abs(py - qy);
            return dis_x * dis_x + dis_y * dis_y; 
        };
        
        vector<vector<int>> g(b.size(), vector<int>{});
        int sz = b.size();
        for (int i = 0; i < sz; i++) {
            long long now_x = b[i][0], now_y = b[i][1], dist = b[i][2];
            for (int j = 0; j < sz; j++) {
                if (i == j) continue;
                auto to_x = b[j][0], to_y = b[j][1];
                if ( distance(now_x, now_y, to_x, to_y) <= (dist * dist) )
                    g[i].push_back(j);
            }
        }
        
        int res = 0;
        for (int i = 0; i < sz; i++) {
            unordered_set<int> tracker {i};
            vector<int> q {i};
            while (q.size()) {
                vector<int> temp;
                for (auto f: q)
                    for (auto to: g[f]) 
                        if (tracker.insert(to).second)
                            temp.push_back(to);
                swap(q, temp);
            }
            res = max(res, (int) tracker.size());
        }
        return res;
    }
};


