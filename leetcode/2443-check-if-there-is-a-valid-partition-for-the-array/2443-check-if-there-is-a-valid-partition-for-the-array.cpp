// class Solution {
// public:
//     bool validPartition(vector<int>& N) {
//         int len = N.size();
//         function<bool(int, bool)> go = [&](auto i, auto is_two) {
//             if (is_two && i == len + 1) return true;
//             else if (!is_two && i == N.size() + 2) return true;
//             else if (i >= N.size()) return false;
//             auto next = go(i + 2, true) || go(i + 3, false);
//             if (is_two) return N[i-1] == N[i] && next;
//             else {
//                 auto is_eq_three = N[i-1] == N[i] && N[i-2] == N[i-1],
//                      is_conseq = N[i-1] + 1 == N[i] && N[i-2] + 1 == N[i-1];
//                 return (is_eq_three || is_conseq) && next;
//             }
//             throw "error";
//         };
//         return go(1, true) || go(2, false) ;
//     }
// };

// class Solution {
// public:
//     bool validPartition(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, bool> dp;
//         function<bool(int)> go = [&](auto i) {
//             if (i == n) return true;
//             if (dp.count(i)) return dp[i];    
//             bool is_possible = false;
//             if (i + 1 < n && nums[i] == nums[i + 1]) is_possible |= go(i + 2);
//             if (i + 2 < n) {
//                  auto three_same = nums[i] == nums[i + 1] && nums[i] == nums[i + 2];
//                  auto three_cons = (nums[i] == nums[i + 1] - 1) 
//                                     && (nums[i + 1] == nums[i + 2] - 1);
//                  if (three_same || three_cons) is_possible |= go(i + 3);
//              }
//             return dp[i] = is_possible;
//         };
//         return go(0);
//     }
// };

// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/solutions/2390497/dp

class Solution {
public:
    bool validPartition(vector<int>& N) {
        vector<bool> dp = {true, false, N[0] == N[1], false};
        auto fin = [](int n) { return n % 4; };
        for (auto i = 2; i < N.size(); ++i) {
            auto two = N[i] == N[i-1],
                 three = (two && N[i-1] == N[i-2]) || (N[i-2] + 1 == N[i-1] && N[i-1] + 1 == N[i]);
            dp[fin(i + 1)] = ( dp[fin(i-1)] && two ) || (dp[fin(i-2)] && three );
        }
        return dp[fin(N.size())];
    }
};