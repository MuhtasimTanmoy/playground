// class Solution {
// public:
//     int search(vector<int>& N, int t) {
//         int l = 0, r = N.size() - 1;
//         int res = -1;
//         while (l < r) {
//             int m = l + (r - l) / 2;
//             if (N[l] > N[r]) {
                
//             } else {
//                 if (t < N[m]) r = m - 1; else l = m;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int search(vector<int>& N, int t) {
        int l = 0, r = N.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (N[l] <= N[m]) {
                if (N[l] <= t && t <= N[m]) r = m; else l = m + 1;
            } else {
                if (N[m] <= t && t <= N[r]) l = m; else r = m - 1;
            }
        }
        return N[l] == t ? l: -1;
    }
};