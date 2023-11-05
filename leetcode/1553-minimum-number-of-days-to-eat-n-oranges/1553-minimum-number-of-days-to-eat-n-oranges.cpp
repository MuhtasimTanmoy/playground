/*
    >>>>>>>>>>> 81 / 176 test cases passed.

    class Solution {
        unordered_map<int, int> dp;
    public:
        int minDays(int n) {
            if (n == 1) return 1;
            if (dp.count(n)) return dp[n];

            int res = INT_MAX;
            if (!(n % 3)) res = 1 + minDays(n - 2 * (n / 3));
            if (!(n % 2)) res = min(res, 1 + minDays(n - n / 2));
            res = min(res, 1 + minDays(n - 1));
            return dp[n] = res;
        }
    };
    
    
    
    >>>>>>>>>>> 19 / 176 test cases passed.

    class Solution {
    public:
        int minDays(int n) {
            vector<pair<int, int>> q; q.push_back({n, 0});
            int res = INT_MAX;
            while (q.size()) {
                vector<pair<int, int>> temp;
                auto l = q.size();
                for (int i = 0; i < l; i++) {
                    auto [now, days] = q[i];
                    if (!now) {
                        res = min(res, days);
                        continue;
                    }
                    if (now % 2 == 0) temp.push_back({now - now / 2, days + 1});
                    if (now % 3 == 0) temp.push_back({now -  2 * (now / 3), days + 1});
                    temp.push_back({now - 1, days + 1});
                }
                swap(temp, q);
            }
            return res;
        }
    };
*/

// class Solution {
// public:
//     int minDays(int n) {
//     }
// };

class Solution {
    unordered_map<int, int> dp;
public:
    int minDays(int n) {
        if (n <= 1) return n;
        if (dp.count(n) == 0)
            dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return dp[n];
    }
};