/*
>> 259 / 283 test cases passed.
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_set<string> dp;
        auto gen_key = [](auto i, auto j) {
            return to_string(i) + "-" + to_string(j);
        };
        
        int res = INT_MAX;
        function<void(int, int)> go = [&](auto i, auto c) {
            if (i >= cost.size()) {
                res = min(res, c);
                return;
            }
            auto key = gen_key(i, c);
            if (dp.count(key)) return;
            go(i + 1, c + cost[i]), go(i + 2, c + cost[i]);
            dp.insert(key);
        };
        go(0, 0), go(1, 0);
        return res;
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> dp;
        function<int(int)> go = [&](auto i) {
            if (i >= cost.size()) return 0;
            if (dp.count(i)) return dp[i];
            
            auto res = min(go(i + 1), go(i + 2));
            return dp[i] = cost[i] + res;
        };
        return min(go(0), go(1));
    }
};
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp {cost[0], cost[1]};
        for (auto i = 2; i < n; i++) {
            auto calc = cost[i] + min(dp[i - 1], dp[i - 2]);
            dp.push_back(calc);
        }
        return min(dp.back(), dp[n - 2]);
    }
};