class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}, visit, res;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pque, aque;
        row = heights.size(), col = heights[0].size();
        visit.resize(row, vector<int>(col, 0));
        
        for (int i = 0; i < row; ++i) {
            pque.push({i,0});
            visit[i][0] |= 0b01;
            aque.push({i,col-1});
            visit[i][col-1] |= 0b10;
        }
        
        for (int j = 0; j < col; ++j) {
            pque.push({0,j});
            visit[0][j] |= 0b01;
            aque.push({row-1, j});
            visit[row-1][j] |= 0b10;
        }
        
        bfs(pque, 0b01, heights);
        bfs(aque, 0b10, heights);
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (visit[i][j] == 3) res.push_back({i,j});
 
        return res;
    }
    void bfs(queue<pair<int,int>> &que, int tag, vector<vector<int>> &heights) {
        
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                
                for (auto &dir: dirs) {
                    int nr = now.first + dir[0];
                    int nc = now.second + dir[1];
                    
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col 
                        || heights[nr][nc] < heights[now.first][now.second] 
                        || (visit[nr][nc] & tag))
                        continue;
                    
                    visit[nr][nc] |= tag;
                    que.push({nr, nc});
                }
            }
        }
    }
};