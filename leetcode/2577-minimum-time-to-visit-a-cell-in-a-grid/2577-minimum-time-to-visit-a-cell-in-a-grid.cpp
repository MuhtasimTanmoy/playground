class Solution {
public:
    // int minimumTime(vector<vector<int>>& G) {
    //     int m = G.size(), n = G.back().size();
    //     vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    //     bool reached = false;
    //     function<int(int, int, int)> go = [&](auto x, auto y, auto time) {
    //         if (x + 1 == m && y + 1 == n) {
    //             reached = true;
    //             return time;
    //         }
    //         cout<<x <<" "<<y<<endl;
    //         int res = INT_MAX;
    //         for (auto dir: dirs) {
    //             auto to_x = x + dir.first, to_y = y + dir.second;
    //             if (to_x < 0 || to_x == m 
    //                 || to_y < 0 || to_y == n
    //                 || G[to_x][to_y] > time || reached) continue;
    //             res = min(res, go(to_x, to_y, time + 1));
    //         }
    //         return res;
    //     };
    //     auto res = go(0, 0, 1);
    //     return res == INT_MAX ? -1: res;
    // }

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        
        while (pq.size()) {
            int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();

            if (row == m - 1 && col == n - 1) return time;

            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (auto dr: dirs) {
                int r = row + dr[0], c = col + dr[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) continue;

                int wait = (grid[r][c] - time) % 2 == 0;
                pq.push({max(grid[r][c] + wait, time + 1), r, c});
            }
        }
        return -1;
    }
};


