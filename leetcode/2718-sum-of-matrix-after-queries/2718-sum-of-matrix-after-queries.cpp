class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& qs) {
        long long ans = 0;
        vector<bool> row(n, true), col(n, true);
        int rows_left = n, cols_left = n;
        for (int i = qs.size() - 1; i >= 0; i--) {
            auto q = qs[i];
            auto type = q[0], idx = q[1], val = q.back();
            if (type) {
                if (rows_left && col[idx])
                    ans += rows_left * val, cols_left--, col[idx] = false;
            } else {
                if (cols_left && row[idx])
                    ans += cols_left * val, rows_left--, row[idx] = false;
            }
        }
        return ans;
    }
};