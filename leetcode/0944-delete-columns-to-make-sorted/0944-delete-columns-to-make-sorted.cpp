class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del = 0;
        for (int index = 0; index < strs[0].size(); index++) {
            auto elem = strs[0][index];
            for (auto str:  strs) {
                if (str[index] < elem) {
                    del++;
                    break;
                }
                elem = str[index];
            }
        }
        return del;
    }
};

// int minDeletionSize(vector<string>& A, int res = 0) {
//     if (A.empty()) return res;
//     for (auto c = 0; c < A[0].size(); ++c)
//         for (auto i = 1; i < A.size(); ++i) {
//             if (A[i - 1][c] > A[i][c]) {
//                 ++res;
//                 break;
//             }
//         }
//     return res;
// }