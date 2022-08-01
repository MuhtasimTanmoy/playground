class Solution {
    int traverse(int m, int n, vector<vector<int>>& v) {
        if (v[m][n] != -1) return v[m][n];
        if (!m && !n) return v[m][n] = 1;
        int count = 0;
        if (m) count += traverse(m - 1, n, v);
        if (n) count += traverse(m, n - 1, v);
        return v[m][n] = count;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> visited(m, vector<int>(n, -1));
        return traverse(m-1, n-1, visited);
    }
};