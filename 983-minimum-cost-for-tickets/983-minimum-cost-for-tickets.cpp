// class Solution {
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         vector<vector<int>> dp(days.size(), vector<int>(366, -1));
//         function<int(int, int)> go = [&](int index, int ticketCoveredTill) -> int {            
//             if (index >= days.size()) return 0;
//             if (dp[index][ticketCoveredTill] != -1) return dp[index][ticketCoveredTill];
            
//             auto curr = days[index];
//             if (curr <= ticketCoveredTill)
//                 return dp[index][ticketCoveredTill] = go(index + 1, ticketCoveredTill);
            
//             auto one = costs[0] + go(index + 1, curr);
//             auto seven = costs[1] + go(index + 1, min(curr + 7 - 1, 365));
//             auto thirty = costs[2] + go(index + 1, min(curr + 30 - 1, 365));
//             return dp[index][ticketCoveredTill] = min(one, min(seven, thirty));
//         };
//         auto ans = go(0, 0);
//         return ans;
//     }
// };

class Solution {
public:
    using VI = vector<int>;
    using fun = function<int(int, int)>;
    using Map = unordered_map<int, int>;
    int mincostTickets(VI& A, VI& cost, VI days = VI{1, 7, 30}, Map m = {}) {
        int N = A.size();
        fun go = [&](auto i, auto day) {
            while (i < N && A[i] < day)
                ++i;
            if (i == N)
                return 0;             // \U0001f6d1 base case
            if (m[i])
                return m[i];          // \U0001f914 memo
            m[i] = int(1e9 + 7);
            for (auto k{ 0 }; k < 3; ++k)
                m[i] = std::min(m[i], cost[k] + go(i, A[i] + days[k]));   // \U0001f3af min cost
            return m[i];
        };
        return go(0, 0);
    }
};