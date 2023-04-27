/*
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(), vector<int>(366, -1));
        function<int(int, int)> go = [&](int index, int ticketCoveredTill) -> int {            
            if (index >= days.size()) return 0;
            if (dp[index][ticketCoveredTill] != -1) return dp[index][ticketCoveredTill];
            auto curr = days[index];
            if (curr <= ticketCoveredTill)
                return dp[index][ticketCoveredTill] = go(index + 1, ticketCoveredTill);
            auto one = costs[0] + go(index + 1, curr);
            auto seven = costs[1] + go(index + 1, min(curr + 7 - 1, 365));
            auto thirty = costs[2] + go(index + 1, min(curr + 30 - 1, 365));
            return dp[index][ticketCoveredTill] = min(one, min(seven, thirty));
        };
        auto ans = go(0, 0);
        return ans;
    }
};

class Solution {
public:
    int mincostTickets(vector<int>& A, 
                       vector<int>& cost, 
                       vector<int> days = vector<int>{1, 7, 30}, 
                       unordered_map<int, int> m = {}) {
        int N = A.size();
        function<int(int, int)> go = [&](auto i, auto day) {
            while (i < N && A[i] < day) ++i;
            if (i == N) return 0;
            if (m[i]) return m[i];
            m[i] = int(1e9 + 7);
            for (auto k{ 0 }; k < 3; ++k)
                m[i] = std::min(m[i], cost[k] + go(i, A[i] + days[k]));
            return m[i];
        };
        return go(0, 0);
    }
};


class Solution {
public:
    int mincostTickets(vector<int>& A, 
                       vector<int>& cost,
                       vector<int> days = vector<int>{1, 7, 30}) {
        auto gen_key = [](auto l, auto ... r) {
            return (to_string(l) + ... + (to_string(r)));
        };
        unordered_map<string, int> cache;
        function<int(int, int)> go = [&](auto idx, auto days_covered) {
            if (idx == A.size()) return 0;
            
            auto key = gen_key(idx, days_covered);
            if (cache.count(key)) return cache[key];
            
            if (days_covered > A[idx]) return cache[key] = go(idx + 1, days_covered);
            
            int min_need = INT_MAX;
            for (int i = 0; i < days.size(); i++) 
                min_need = min(min_need, cost[i] + go(idx + 1, A[idx] + days[i]));
            return cache[key] = min_need;
        };
        return go(0, 0);
    }
};
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, 
                       vector<int>& costs) {
        int n = days.back();
        vector<int> dp(n + 1);

        for (int& day: days) dp[day] = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (dp[i] == 0) dp[i] = dp[i - 1];
            else
                dp[i] = min({dp[i - 1         ] + costs[0],
                             dp[max(0, i -  7)] + costs[1],
                             dp[max(0, i - 30)] + costs[2]});
        }

        return dp[n];
    }
};