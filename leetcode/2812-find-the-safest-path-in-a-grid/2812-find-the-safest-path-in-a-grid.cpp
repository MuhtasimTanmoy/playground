// class Solution {
// public:
//     int maximumSafenessFactor(vector<vector<int>>& g) {
//         int m = g.size(), n = g[0].size();
//         if (g[0][0] || g[m - 1][n - 1]) return 0;
        
//         vector<pair<int, int>> thieves;
//         for (int i = 0; i < g.size(); i++)
//             for (int j = 0; j < g[i].size(); j++)
//                 thieves.push_back({i, j});
        
//         auto is_valid = [&](auto i, auto j) {
//             if (i < 0 || i == m) return false;
//             if (j < 0 || j == n) return false;
//             return g[i][j] == 0;
//         };
        
//         vector<int> dirs = {-1, 0, 1, 0, -1};
//         while (thieves.size()) {
//             vector<pair<int, int>> temp;
//             for (auto [pos_x, pos_y]: thieves) 
//                 for (int i = 0; i < 4; i++) {
//                     auto to_x = pos_x + dirs[i], to_y = pos_y + dirs[i + 1];
//                     if (is_valid(to_x, to_y)) 
//                         g[to_x][to_y] = g[pos_x][pos_y] + 1,
//                         temp.push_back({to_x, to_y});
//                 }
//             swap(temp, thieves);
//         }
        
//         for (auto row: g) {
//             for (auto c: row)
//                 cout<<c<<" ";
//             cout<<endl;
//         }

//         vector<vector<bool>> visited(m, vector(n, false));
//         visited[0][0] = 1;
        
//         auto is_valid_traverse = [&](auto i, auto j) {
//             if (i < 0 || i == m) return false;
//             if (j < 0 || j == n) return false;
//             if (visited[i][j]) return false;
//             return true;
//         };
        
//         function<int(int, int)> traverse = [&](auto i,  auto j) {
//             if (i == m - 1 && j == n - 1) return g[i][j];
            
//             int res = g[i][j];
//             if (res == 1) return 1;
            
//             for (int i = 0; i < 4; i++) {
//                 auto to_x = i + dirs[i], to_y = j + dirs[i + 1];
//                 if (is_valid_traverse(to_x, to_y)) 
//                     visited[to_x][to_y] = 1,
//                     res = max(res, traverse(to_x, to_y));
//             }
//             return res;
//         };
        
//         return traverse(0, 0) - 1;
//     }
// };


class Solution {
    public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> ts;
        priority_queue<array<int, 3>> pq;
        
        int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j])
                    ts.push({1, i, j});
        
        while (ts.size()) {
            auto [sf, i, j] = ts.top(); ts.pop();
            if (g[i][j] != sf) continue;
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n 
                    && (g[x][y] == 0 ||  g[x][y] > sf + 1)) 
                    g[x][y] = sf + 1,
                    ts.push({sf + 1, x, y});
            }
        }
        
        pq.push({g[0][0], 0, 0});
        while (pq.size()) {
            auto [sf, i, j] = pq.top(); pq.pop();
            if (i == n - 1 && j == n - 1) return sf - 1;
            
            if (g[i][j] == -1) continue;
            g[i][j] = -1;
            
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n && g[x][y] != -1) 
                    pq.push({min(sf, g[x][y]), x, y});
            }
        }
        return 0;
    }
};