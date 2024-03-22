class Solution {
public:
//     int maxOperations(vector<int>& nums) {
//         unordered_map<string, int> dp;
//         auto gen_key = [](auto a, auto b, auto c) {
//              return to_string(a) + "-" + to_string(b) + "-" + to_string(c);
//         };
//         function<int(int, int, int)> go = [&](auto l, auto r, auto n) {
//             if (r <= l) return 0;
//             auto left = nums[l] + nums[l + 1], 
//                  right = nums[r] + nums[r - 1],
//                  both = nums[l] + nums[r];
//             auto key = gen_key(l, r, n);
//             if (dp.count(key)) return dp[key];
//             int res = -1;
//             if (n == -1 || left == n) res = go(l + 2, r, left);
//             if (n == -1 || right == n) res = max(res, go(l, r - 2, right));
//             if (n == -1 || both == n) res = max(res, go(l + 1, r - 1, both));
//             return dp[key] = res == -1 ? 0: 1 + res;
//         };
//         return go(0, nums.size() - 1, -1);
//     }
    
    int maxOperations(vector<int>& nums) {
        int dp[2001][2001];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> go = [&](auto l, auto r, auto n) {
            if (r <= l) return 0;
            auto left = nums[l] + nums[l + 1], 
                 right = nums[r] + nums[r - 1],
                 both = nums[l] + nums[r];
            if (dp[l][r] != -1) return dp[l][r];
            int res = -1;
            if (n == -1 || left == n) res = go(l + 2, r, left);
            if (n == -1 || right == n) res = max(res, go(l, r - 2, right));
            if (n == -1 || both == n) res = max(res, go(l + 1, r - 1, both));
            return dp[l][r] = res == -1 ? 0: 1 + res;
        };
        return go(0, nums.size() - 1, -1);
    }
};