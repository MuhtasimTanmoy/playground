// DP with memo
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        auto ok = [](auto x) { return 1 <= x && x <= 26; };
        unordered_map<int, int> bag;
        function<int(int)> go = [&](int index) {
            if (bag.count(index)) return bag[index];
            if (index == len) return 1;
            auto one = s[index] - '0';
            auto two = (one && (index + 1) < len) ? stoi(s.substr(index, 2)) : 0;
            return bag[index] = (ok(one) ? go(index+1): 0) + (ok(two) ? go(index+2): 0);
        };
        return go(0);
    }
};

// Iterative DP
// class Solution {
// public:
//     int numDecodings(string s) {
//         int len = s.size();
//         auto ok = [](auto x) { return 1 <= x && x <= 26; };
//         vector<int> dp(len + 1); dp[len] = 1;
//         for (int i {len - 1}; i >= 0; i--) {
//             auto one = s[i] - '0';
//             auto two = one && i + 1 < len ? stoi(s.substr(i, 2)): 0;
//             if (ok(one)) dp[i] += dp[i+1];
//             if (ok(two)) dp[i] += dp[i+2];
//         }
//         return dp[0];
//     }
// };


// Constant space
// Iterative DP
// class Solution {
// public:
//     int numDecodings(string s) {
//         int len = s.size();
//         auto ok = [](auto x) { return 1 <= x && x <= 26; };
//         int first = 1, second = 0;
//         for (int i {len - 1}; i >= 0; i--) {
//             auto one = s[i] - '0';
//             auto two = one && i + 1 < len ? stoi(s.substr(i, 2)): 0;
            
//             int sum = 0;
//             if (ok(one)) sum = first;
//             if (ok(two)) sum += second;
            
//             second = first;
//             first = sum;
//         }
//         return first;
//     }
// };