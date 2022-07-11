class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = size(target);
        vector<int> degree(4, 1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                degree[0] &= (target[i][j] == mat[i][j]);
                degree[1] &= (target[i][j] == mat[j][n-i-1]);
                degree[2] &= (target[i][j] == mat[n-i-1][n-j-1]);
                degree[3] &= (target[i][j] == mat[n-j-1][i]);
            }
        return degree[0] || degree[1] || degree[2] || degree[3];
    }
};