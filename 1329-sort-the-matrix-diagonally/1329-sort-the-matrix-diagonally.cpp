class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int p = 0; p < n + m; ++p) {
            vector<int> v;
            int pi = p < m ? p : 0, pj = max(0, p - m + 1);
            for (int i = pi, j = pj; i < m && j < n; ++i, ++j)
                v.push_back(mat[i][j]);
            sort(begin(v), end(v));
            for (int i = pi, j = pj, vp = 0; i < m && j < n; ++i, ++j, ++vp)
                mat[i][j] = v[vp];        
        }
        return mat;
    }
};