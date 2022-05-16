class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int row, col;
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        row = image.size(), col = image[0].size();
        if (image[sr][sc] == newColor) return image;
        dfs(sr, sc, image, image[sr][sc], newColor);
        return image;
    }
    
    void dfs(int r, int c, vector<vector<int>> &image, int ocolor, int ncolor) {
        image[r][c] = ncolor;
        
        for (auto &dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || image[nr][nc] != ocolor) 
                continue;
            
            dfs(nr, nc, image, ocolor, ncolor);
        }
    }
};