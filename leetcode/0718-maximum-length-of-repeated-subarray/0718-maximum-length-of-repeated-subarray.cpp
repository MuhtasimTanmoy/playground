// Wrong soilution
// Fails in the follwing case
// [1,0,0,0,1]
// [1,0,0,1,1]
/*
class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        unordered_map<string, int> dp;
        auto key = [](int i, int j, bool k) { 
            return to_string(i) + "-" + to_string(j) + "-" + to_string(k); 
        };
        
        function<int(int, int, bool)> go = [&](auto i1, auto i2, auto isPrev) {
            if (i1 == n1.size() || i2 == n2.size()) return 0;
            
            auto k = key(i1, i2, isPrev);
            if (dp.count(k)) return dp[k];
            
            int res = 0;
            if (n1[i1] == n2[i2]) {
                res = 1 + go(i1 + 1, i2 + 1, true);
            } else if (isPrev) return dp[k] = 0;
            res = max(res, go(i1 + 1, i2, false));
            res = max(res, go(i1, i2 + 1, false));
            return dp[k] = res;
        };
        
        return go(0, 0, false);
    }
};


class Solution {
public:
    using VI = vector<int>;
    using fun = function<int(int, int, int)>;
    using Map = unordered_map<string, int>;
    int findLength(VI& A, VI& B, Map m = {}) {
        int M = A.size(),
            N = B.size();
        fun go = [&](auto i, auto j, auto k) {
            if (i == M || j == N)
                return k;
            stringstream key; key << i << "," << j << "," << k;
            if (m.find(key.str()) != m.end())
                return m[key.str()];
            auto a = A[i] == B[j] ? go(i + 1, j + 1, k + 1) : k,
                 b = go(i + 1, j, 0),
                 c = go(i, j + 1, 0);
            return m[key.str()] = max({ a, b, c });
        };
        return go(0, 0, 0);
    }
};

*/


// class Solution {
// public:
//     using VI = vector<int>;
//     using VVI = vector<VI>;
//     int findLength(VI& A, VI& B, int best = 0) {
//         int res = 0;
//         int M = A.size(),
//             N = B.size();
//         VVI dp(M + 1, VI(N + 1));
//         for (auto i{ 1 }; i <= M; ++i)
//             for (auto j{ 1 }; j <= N; ++j)
//                 if (A[i - 1] == B[j - 1]) {
//                     dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
//                     res = max(res, dp[i][j]);
//                 }
//         return res;
//     }
// };


class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B, int best = 0) {
        int res = 0;
        int M = A.size(), N = B.size();
        vector<int> dp(N + 1);
        for (auto i{ 1 }; i <= M; ++i) {
            vector<int> temp(N + 1);
            for (auto j{ 1 }; j <= N; ++j)
                if (A[i - 1] == B[j - 1]) {
                    temp[j] = max(temp[j], 1 + dp[j-1]);
                    res = max(res, temp[j]);
                }
            swap(temp, dp);
        }
        return res;
    }
};