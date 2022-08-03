// TLE
// class Solution {
// public:
//     int countPaths(vector<vector<int>>& grid) {
//         int lenY = size(grid), lenX = size(grid[0]);
//         int mod = 1e9 + 7;
//         unordered_map<string, int> cache;
        
//         auto gen = [](int i, int j) {
//             stringstream ss; ss<<i<< " " <<j;
//             return ss.str();
//         };
        
//         auto convert = [](int i, int j) {
//             return vector<pair<int, int>>{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}};
//         };
        
//         function<int(int, int)> go = [&](int i, int j) -> int {
//             auto key = gen(i, j);
//             int count = 1;
//             if (cache.count(key)) return cache[key];
//             auto directions = convert(i, j);
//             for (auto [u, v]: directions)
//                 if (u < lenY && u >= 0 && v < lenX && v >= 0 && grid[u][v] > grid[i][j]) 
//                     count = (count + go(u,v)) % mod;
//             return cache[key] = count;
//         };
        
//         int res = 0;
//         for (int i = 0; i < lenY; i++)
//             for (int j = 0; j < lenX; j++) 
//                 res = (res + go(i, j)) % mod;
//         return res;
//     }
// };


class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Pair = pair<int, int>;
    using Pairs = vector<Pair>;
    using Triple = tuple<int, int, int>;
    using Triples = vector<Triple>;    
    
    int countPaths(VVI& A, int MOD = 1e9 + 7, int paths = 0) {
        int M = A.size(), N = A[0].size();
        VVI dp(M, VI(N, 1));
        Triples sorted;
        
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                sorted.emplace_back(A[i][j], i, j);
        
        sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
            auto [x, i1, j1] = a;
            auto [y, i2, j2] = b;
            return y < x;
        });
        
        for (auto [_, i, j]: sorted)
            for (auto [u, v]: Pairs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}})
                if (0 <= u && u < M && 0 <= v && v < N && A[i][j] < A[u][v])
                    dp[i][j] = (dp[i][j] + dp[u][v]) % MOD;
        
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                paths = (paths + dp[i][j]) % MOD;
        
        return paths;
    }
};
