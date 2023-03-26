// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
        
//         vector<vector<int>> calc(matrix.size(), vector<int>(matrix[0].size(), 0));
//         for (int i = 0; i < matrix[0].size(); i++)
//             calc[0][i] = i 
//             ? (matrix[0][i] == matrix[0][i-1] && matrix[0][i] == '1') ? calc[0][i-1] + 1: 0 
//             : matrix[0][i] == '1';
        
//         for (int i = 0; i < matrix.size(); i++)
//             calc[i][0] = i 
//             ? (matrix[i][0] == matrix[i-1][0] && matrix[i][0] == '1') ? calc[i-1][0] + 1: 0 
//             : matrix[i][0] == '1';
        
//         int res = 0;
//         for (int i = 1; i < matrix.size(); i++)
//             for (int j = 1; j < matrix[i].size(); j++) {
//                 calc[i][j] = min({calc[i-1][j], calc[i][j-1], calc[i-1][j-1]}) + matrix[i][j] == '1';
//                 res = max(res, calc[i][j]);
//             }
        
//         for (int i = 0; i < matrix.size(); i++) {
//             for (int j = 0; j < matrix[i].size(); j++)
//                 cout<<calc[i][j]<<" ";
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maximalSquare(vector<vector<char>>& A, int best = 0) {
        int M = A.size(), N = A[0].size();
        vector<int> pre(N);
        
        for (auto j{ 0 }; j < N; ++j)
            pre[j] = A[0][j] == '1', best = max(best, pre[j]);
        
        for (auto i{ 1 }; i < M; ++i) {
            vector<int> cur(N);
            cur[0] = A[i][0] == '1', best = max(best, cur[0]);
            for (auto j{ 1 }; j < N; ++j) {
                if (A[i][j] == '0')
                    continue;
                auto U = pre[j],
                     L = cur[j - 1],
                     X = pre[j - 1];
                cur[j] = 1 + min({ U, L, X });
                best = max(best, cur[j]);
            }
            swap(pre, cur);
        }
        return best * best;
    }
};