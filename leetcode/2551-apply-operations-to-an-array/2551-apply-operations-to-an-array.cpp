// class Solution {
// public:
//     vector<int> applyOperations(vector<int>& N) {
//         int n = N.size();
//         vector<int> up(N.begin(), N.end());
//         bool got_one = false;
//         while (up.size()) {
//             vector<int> to;
//             for (auto i = 0; i < up.size() - 1; i++) {
//                 if (up[i] && up[i] == up[i+1])  
//                     to.push_back(up[i] * 2), up[i] = 0, up[i + 1] = 0, got_one = true;
//                 else if (up[i]) to.push_back(up[i]);
//             }
//             if (up.back()) to.push_back(up.back());
//             up = to;

//             if (got_one == false) break;
//             got_one = false;
//         }
//         auto fill = n - up.size();
//         while (fill--) up.push_back(0);
//         return up;
//     }
// };

class Solution {
public:
    vector<int> applyOperations(vector<int>& N) {
        int n = N.size();
        vector<int> to;
        for (auto i = 0; i < N.size() - 1; i++) {
            if (N[i] && N[i] == N[i+1])
                to.push_back(N[i] * 2), N[i] = 0, N[i + 1] = 0;
            else if (N[i]) to.push_back(N[i]);
        }
        if (N.back()) to.push_back(N.back());
        auto fill = n - to.size();
        while (fill--) to.push_back(0);
        return to;
    }
};