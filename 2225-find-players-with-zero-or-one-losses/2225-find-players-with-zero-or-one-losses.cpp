class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        unordered_set<int> winners;
        for (auto match: matches) {
            winners.insert(match[0]);
            lost[match[1]]++;
        }
        vector<vector<int>> res(2, vector<int>());
        for (auto winner: winners) if (lost.count(winner) == 0) res[0].push_back(winner);
        for (auto [who, count]: lost) if (count == 1) res[1].push_back(who);
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};
