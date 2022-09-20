// class Solution {
// public:
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), INT_MIN));
//         function<int(int, int, int)> traverse = 
//             [&](int left, int right, int mIndex) -> int {
//                 if (mIndex >= multipliers.size()) return 0;
//                 if (dp[left][right] != INT_MIN) return dp[left][right];
//                 auto leftPoint = nums[left] * multipliers[mIndex] + traverse(left + 1, right, mIndex + 1);
//                 auto rightPoint = nums[right] * multipliers[mIndex] + traverse(left, right - 1, mIndex + 1);
//                 return dp[left][right] = max(leftPoint, rightPoint);
//         };
//         return traverse(0, nums.size() - 1, 0);
//     }
// };

class Solution {
public:
/*
C++ Classic DP

Classic DP with left and right pointers. The only trick here is to pick memoisation parameters: it would be great if we only need 1000 * 1000 matrix instead of 100000 * 100000!

Since `i` is limited to `1000`, the left pointer `l` cannot be larger than `1000`.

Therefore, we can memoise `i` and `l` in `dp[1001][1001]`, and just compute the right pointer `r`.

**C++**
*/
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
        if (i >= mults.size()) return 0;
        if (dp[l][i] == INT_MIN) {
            int r = nums.size() - 1 - (i - l);
            auto left = nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1),
                 right = nums[r] * mults[i] + dfs(nums, mults, l, i + 1);
            dp[l][i] = max(left, right);
        }
        return dp[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& mults) {
        dp = vector<vector<int>>(mults.size(), vector<int>(mults.size(), INT_MIN));
        return dfs(nums, mults, 0, 0);
    }
};

// class Solution {
// public:
//     using VI = vector<int>;
//     using VVI = vector<VI>;
//     int maximumScore(VI& A, VI& X) {
//         int N = A.size(),
//             M = X.size();
//         VVI dp(M + 1, VI(M + 1));
//         for (auto k{ M - 1 }; 0 <= k; --k) {
//             for (auto i{ k }; 0 <= i; --i) {
//                 auto j = N - 1 - (k - i);
//                 auto L = A[i] * X[k] + dp[i + 1][k + 1],
//                      R = A[j] * X[k] + dp[i][k + 1];
//                 dp[i][k] = max(L, R);
//             }
//         }
//         return dp[0][0];
//     }
// };