// class Solution {
// public:
//     int longestEqualSubarray(vector<int>& N, int k) {

//         // vector<vector<vector<int>>> dp(N.size() + 1, 
//         //                              vector<vector<int>>(1e5 + 1, 
//         //                              vector<int>(1e5 + 1, -1)));

//         function<int(int, int, int)> go = [&](auto i, auto prev, auto left) {

//             if (i == N.size() || left == -1) return 0;

//             // if (dp[i][prev][left] == -1) return dp[i][prev][left];

//             int res = 0;

//             if (N[i] == prev) res = max(res, 1 + go(i + 1, prev, left)); 
//             else res = max(res, go(i + 1, prev, left - 1));

//             res = max(res, go(i + 1, N[i], k));

//             cout<<i<<" | prev "<<prev<<" | left "<<left<<" | res: "<<res<<endl;

//             // return dp[i][prev][left] = res;

//             return res;
//         };
//         return go(0, -1, k) + 1;
//     }
// };

// [4,4,2,2,4]

/*
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        unordered_map<string, int> dp;
        auto gen_key = [](int a, int b, int c, int d) {
            return to_string(a) + "-" + to_string(b) + "-" + to_string(c) + "-" + to_string(d);
        };
        
        int n = nums.size();
        function<int(int, int, int, int)> go = [&](auto i, auto prev, auto count, auto left) {
            if (i == n || left < 0) return count;
            
            auto key = gen_key(i, prev, count, left);
            if (dp.count(key)) return dp[key];
            
            int res = 0;
            if (nums[i] == prev) res = max(res, go(i + 1, prev, count + 1, left));
            else res = max(res, go(i + 1, prev, count, left - 1));
            
            res = max(res, go(i + 1, nums[i], 1, left));
            return  dp[key] = res;
        };
        
        return go(1, nums.front(), 1, k);
    }
};
*/

// class Solution {
// public:
//     // int longestEqualSubarray(vector<int>& nums, int k) {
//     //     unordered_map<int, vector<int>> counter;
//     //     for (int i = 0; i < nums.size(); i++) counter[nums[i]].push_back(i);
//     //     int res = 0;
//     //     for (auto [num, ids]: counter) {
//     //         int j = 0, i = 1;
//     //         for (int bal = k; i < ids.size(); i++) {
//     //             bal -= ids[i] - ids[i-1] - 1;
//     //             if (bal < 0)
//     //                 bal += ids[++j] - ids[j-1] - 1;
//     //         }
//     //         res = max(res, i - j);   
//     //     }
//     //     return res;
//     // }

//     int longestEqualSubarray(vector<int>& A, int k) {
//         int maxf = 0, i = 0, n = A.size();
//         unordered_map<int, int> count;
//         for (int j = 0; j < n; j++) {
//             maxf = max(maxf, ++count[A[j]]);
//             if (j - i + 1 - maxf > k) --count[A[i++]];
//         }
//         return maxf;
//     }
// };

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0, j = 0; i < n; i++) {
            ans = max(ans, ++freq[nums[i]]);
            if (i - j - ans >= k) --freq[nums[j++]];
        }
        return ans;
    }
};