class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> res;
        
        int r = 0, c = 0, 
        row = matrix.size(), col = matrix[0].size(), d = 0,
        cnt = row * col;
        
        while (cnt--) {
            res.push_back(matrix[r][c]);
            matrix[r][c] = -101;
            int nr = r + dirs[d][0], nc = c + dirs[d][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[nr][nc] == -101)
                d = (d+1) % 4,
                r += dirs[d][0], c += dirs[d][1];
            else
                r = nr, c = nc;
        }
        return res;
    }
};