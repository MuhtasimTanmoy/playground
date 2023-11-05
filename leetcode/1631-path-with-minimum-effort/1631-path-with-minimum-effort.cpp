/*
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int res = INT_MAX, m = h.size() - 1, n = h.back().size() - 1;
        vector<vector<bool>> visited(101, vector<bool>(101, false));
        vector<int> dirs = {-1, 0, 1, 0, -1};
        unordered_set<string> bag;
        auto gen_key = [](auto i, auto j, auto k) {
            return to_string(i) + "-" + to_string(j) + "-" + to_string(k);
        };
        function<void(int, int, int)> go = [&](auto i, auto j, auto x) {
            if (i == m && j == n) {
                res = min(res, x);
                return;
            }
            
            auto key = gen_key(i, j, x);
            if (bag.count(key)) return;
            bag.insert(key);
            
            auto val = h[i][j];
            for (int k = 1; k < dirs.size(); k++) {
                auto to_x = i + dirs[k-1], to_y = j + dirs[k];
                if (min(to_x, to_y) >= 0 
                    && to_x <= m && to_y <= n 
                    && !visited[to_x][to_y]) {
                    
                    auto diff = max(abs(h[to_x][to_y] - val), x);
                    if (diff >= res) continue;
                    visited[to_x][to_y] = true;
                    go(to_x, to_y, max(diff, x));
                    visited[to_x][to_y] = false;
                }
            }
        };
        go(0, 0, 0);
        return res;
    }
};
*/

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    int dirs[5] = {-1, 0, 1, 0, -1};

    std::vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.emplace(0, 0);
      
    while (pq.size()) {
      int effort = pq.top().first;
      int x = pq.top().second / 100, y = pq.top().second % 100;
      pq.pop();

      if (x == m - 1 && y == n - 1) return effort;
      if (effort >= efforts[x][y]) continue;
      efforts[x][y] = effort;

      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i], ny = y + dirs[i + 1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
        pq.emplace(n_effort, nx * 100 + ny);
      }
    }
    return -1;
  }
};