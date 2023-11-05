/*

256 / 1566 test cases passed.

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long multi = 1;
        for (auto row: grid) for (auto elem: row) multi *= elem;
        for (auto &row: grid)
            for (auto &elem: row) {
                long long val = multi / (long long) elem;
                val %= 12345;
                elem = val;
            }
        return grid;
    }
};
*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        long pre = 1, suf = 1, MOD = 12345;
        vector<vector<int>> A(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                A[i][j] = pre * A[i][j] % MOD,
                A[n - i - 1][m - j - 1] = suf * A[n - i - 1][m - j - 1] % MOD,
                pre = pre * grid[i][j] % MOD,
                suf = suf * grid[n - i - 1][m - j - 1] % MOD;
        return A;
    }
};