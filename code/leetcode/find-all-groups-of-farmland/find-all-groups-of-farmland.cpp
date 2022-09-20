class Solution {
public:    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size(), col = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) {
                if (!land[i][j])  continue;
                if ((!i || !land[i-1][j]) && (!j || !land[i][j-1])) {
                    int r = i, c = j;
                    while (r+1 < row && land[r+1][c]) ++r;
                    while (c+1 < col && land[r][c+1]) ++c;
                    res.push_back({i,j,r,c});
                }
            }
        return res;
    }
    
};