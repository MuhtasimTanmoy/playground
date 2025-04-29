// // You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
// // solve
// //     - you will be unable to solve each of the next brainpoweri questions.
// // skip
// //     - next
// // maximum points
// // 10 ^ 5


// class Solution {
// public:
//     long long mostPoints(vector<vector<int>>& Q) {
//         unordered_map<int, long long> bag;
//         function<long long(int)> go = [&](auto i) {
//             if (i >= Q.size()) return 0LL;
//             if (bag.count(i)) return bag[i];
//             auto with = go(i + 1),
//                  without = Q[i][0] + go(i + Q[i][1] + 1);
//             return bag[i] = max(with, without);
//         };
//         return go(0);
//     }
// };


// class Solution {
// public:
//     long long mostPoints(vector<vector<int>>& Q) {
//         unordered_map<int, long long> dp;
//         dp[Q.size()] = 0;

//         function<long long(int)> go = [&](auto i) {
//             auto without = dp[i + 1],
//                  with = Q[i][0] + dp[i + Q[i][1] + 1];
//             return max(with, without);
//         };

//         for (int i = Q.size() - 1; i >= 0; i--) dp[i] = go(i);
//         return dp[0];
//     }
// };


class Solution {
public:
    long long mostPoints(vector<vector<int>>& Q) {
        vector<long long> dp(2 * 1e5 + 1, 0);
        for (int i = Q.size() - 1; i >= 0; i--) {
            auto without = dp[i + 1],
                 with = Q[i][0] + dp[i + Q[i][1] + 1];
            dp[i] = max(with, without);
        }
        return dp[0];
    }
};




// class Solution {
// public:
//     long long mostPoints(vector<vector<int>>& qs) {
//         unordered_map<int, long long> bag;
//         function<long long(int)> go = [&](auto idx) {
//             if (idx >= qs.size()) return 0LL;
//             if (bag.count(idx)) return bag[idx];

//             auto with = qs[idx][0] + go(idx + qs[idx][1] + 1),
//                  without = go(idx + 1);
//             return bag[idx] = max(with, without);
//         };
//         return go(0);
//     }
// };


// class Solution {
// public:
//     long long mostPoints(vector<vector<int>>& qs) {
//         auto gen_key = [](int a, int b) {
//             return to_string(a) + "-" + to_string(b);
//         };
//         unordered_map<string, long long> bag;
//         function<long long(int, int)> go = [&](auto idx, auto left) {
//             if (idx == qs.size()) return 0LL;
//             auto key = gen_key(idx, left);
//             if (bag.count(key)) return bag[key];
//             if (left) return bag[key] = go(idx + 1, left - 1);
//             auto with = qs[idx][0] + go(idx + 1, qs[idx][1]),
//                  without = go(idx + 1, 0);
//             return bag[key] = max(with, without);
//         };
//         return go(0, 0);
//     }
// };