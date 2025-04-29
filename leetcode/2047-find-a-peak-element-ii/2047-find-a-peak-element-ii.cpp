// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& G) {
//         int u = 0, d = G.size() - 1;
//         while (u < d) {
//             auto m = u + (d - u) / 2;
//             if (G[m + 1].front() > G[m].front()) u = m + 1;
//             else d = m;
//         }
//         int l = 0, r = G[u].size() - 1;
//         while (l < r) {
//             auto m = l + (r - l) / 2;
//             if (G[u][m+1] > G[u][m]) l = m + 1;
//             else r = m;
//         }
//         return {u, l};
//     }
// };

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat[0].size() - 1, len = mat[0].size();
        while (l <= r) {
            int m_row = 0, m = l + (r - l) / 2;
            for (auto row = 1; row < mat.size(); row++)
                if (mat[row][m] >= mat[m_row][m])
                    m_row = row;

            auto left = m ? mat[m_row][m - 1] < mat[m_row][m]: true,
                 right = m + 1 < len ? mat[m_row][m + 1] < mat[m_row][m]: true;
                 
            if (left && right) return vector<int>{ m_row, m};
            else if (left) l = m + 1;
            else r = m;
        }
        return {-1, -1};
    }
};