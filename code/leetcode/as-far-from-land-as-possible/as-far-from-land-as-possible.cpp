class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size(), res = 0;
        
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        queue<pair<int,int>> que;
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j]) que.push({i,j});
  
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &dir: dirs) {
                    int nr = now.first + dir[0];
                    int nc = now.second + dir[1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc])
                        continue;
                    grid[nr][nc] = grid[now.first][now.second]+1;
                    res = max(res, grid[nr][nc]);
                    que.push({nr,nc});
                }
            }
        }
        return res-1;
    }
};