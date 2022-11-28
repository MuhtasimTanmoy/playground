class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> atleastWinner;
        map<int, int> lostTracker;
        for (auto match: matches) {
            auto winner = match[0], loser = match[1];
            atleastWinner.insert(winner);
            lostTracker[loser]++;
        }
        
        vector<int> noLoser;
        for (auto winner: atleastWinner) 
            if (lostTracker.count(winner) == 0) 
                noLoser.push_back(winner);
        
        vector<int> onceLost;
        for (auto [key, val]: lostTracker) 
            if (val == 1) 
                onceLost.push_back(key);
        
        return {noLoser, onceLost};
    }
};