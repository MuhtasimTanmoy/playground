// class Solution {
// public:
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         unordered_map<string, int> cache;
//         auto gen_key = [](auto l, auto ... r) {
//             return (to_string(l) + ... + ("-" + to_string(r)));
//         };
        
//         vector<int> frontier(piles.size());
//         function<int(int, int)> go = [&](int col, int left) {
//             if (left == 0 || col == piles.size()) return 0;
            
//             auto key = gen_key(col, left);
//             // if (cache.count(key)) return cache[key];
            
//             int count = 0;
//             for (int i = col; i < piles.size(); i++) {
//                 auto index = frontier[i];
//                 if (index == piles[i].size()) continue;
                
//                 auto not_take = go(col + 1, left);
//                 frontier[i]++;
//                 auto take = piles[i][index] + go(col, left - 1);
//                 count = max(not_take, take);
//             }
//             return cache[key] = count;
//         };
//         return go(0, k);
//     }
// };

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& A, int K) {
        int n = A.size();
        vector<vector<int>> memo(n + 1, vector<int>(K + 1, 0));
        function<int(int, int)> dp = [&](int i, int k) {
            if (memo[i][k] > 0) return memo[i][k];
            if (i == n || k == 0) return 0;
            
            int res = dp(i + 1, k), cur = 0;
            for (int j = 0; j < A[i].size() && j < k; ++j) {
                cur += A[i][j];
                res = max(res, dp(i + 1, k - j - 1) + cur);
            }
            memo[i][k] = res;
            return res;
        };
        return dp(0, K);
    }
};