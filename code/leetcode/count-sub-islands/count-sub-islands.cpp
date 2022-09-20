class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        
        bool found = true;
        vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
        
        function<void (int, int)> traverseMark = [&] (int x, int y) {
            if (grid1[x][y] != grid2[x][y]) { 
                found = false; 
                return; 
            }
            grid2[x][y] = 0;
            for (auto direction: directions) {
                int nx = x + direction.first;
                int ny = y + direction.second;
                if (nx < 0 
                    || ny < 0 
                    || nx >= grid2.size() 
                    || ny >= grid2[0].size() 
                    || !grid2[nx][ny]) continue;
                traverseMark(nx, ny);
            }
        };
        
        for(int i = 0; i < grid2.size(); i++)
            for(int j = 0; j < grid2[i].size(); j++)
                if (grid1[i][j] == grid2[i][j] && grid2[i][j]) {
                    found = true;
                    traverseMark(i, j);
                    if (found) count++;
                }
            
        return count;
    }
};