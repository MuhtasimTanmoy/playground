// class Solution {
// public:
//     vector<int> maxPoints(vector<vector<int>>& G, vector<int>& Q) {
//         vector<int> res;
//         vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
//         for (auto q: Q) {
//             if (G[0][0] >= q) {
//                 res.push_back(0);
//                 continue;
//             }
//             vector<vector<int>> v(G.size(), vector<int>(G.back().size(), false));
//             auto is_valid = [&](pair<int, int> p) {
//                 auto [x, y] = p;
//                 if (x < 0 || x == G.size()) return false;
//                 if (y < 0 || y == G.back().size()) return false;
//                 return v[x][y] == false;
//             };
//             vector<pair<int, int>> points = {{0, 0}};
//             v[0][0] = true;
//             int count = 1;
//             while (points.size()) {
//                 vector<pair<int, int>> updated;
//                 for (auto now: points) {
//                     for (auto dir: dirs) {
//                         auto to_x = now.first + dir.first,
//                              to_y = now.second + dir.second;
//                         if (is_valid({to_x, to_y}) && G[to_x][to_y] < q) {
//                             v[to_x][to_y] = true;
//                             updated.push_back({to_x, to_y});
//                             count++;
//                         }
//                     }
//                 }
//                 points = updated;
//             }
//             res.push_back(count);
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& Q) {
        int rows = grid.size(), cols = grid[0].size();

        vector<pair<int, int>> sq;
        for (int i = 0; i < Q.size(); i++) sq.emplace_back(Q[i], i);
        sort(sq.begin(), sq.end());

        vector<int> result(Q.size(), 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        minHeap.emplace(grid[0][0], make_pair(0, 0));
        visited[0][0] = true;

        int points = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& [queryVal, queryIdx]: sq) {
            while (minHeap.size() && minHeap.top().first < queryVal) {
                auto [val, pos] = minHeap.top(); minHeap.pop();
                auto [row, col] = pos;
                points++;

                for (auto& [dr, dc] : dirs) {
                    int nr = row + dr, nc = col + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) 
                        minHeap.emplace(grid[nr][nc], make_pair(nr, nc)),
                        visited[nr][nc] = true;
                }
            }
            result[queryIdx] = points;
        }

        return result;
    }
};