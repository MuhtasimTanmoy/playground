class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), res = 0;
        for (int i = 0; i < n; i++) {
            auto mirror = n - i - 1;
            res += mat[i][i] + (i != mirror ? mat[i][mirror]: 0);
        }
        return res;
    }
};