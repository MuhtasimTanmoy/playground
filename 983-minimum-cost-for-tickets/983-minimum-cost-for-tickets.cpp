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