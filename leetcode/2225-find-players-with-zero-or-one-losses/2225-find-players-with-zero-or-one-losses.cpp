/*
set map
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


map only
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lostTracker;
        for (auto match: matches) {
            auto winner = match[0], loser = match[1];
            if (lostTracker.count(winner) == 0)
                lostTracker[winner] = 0;
            lostTracker[loser]++;
        }
        
        vector<int> noLoser, onceLost;
        for (auto [key, val]: lostTracker) 
            if (val == 1) 
                onceLost.push_back(key);
            else if (val == 0)
                noLoser.push_back(key);
        
        return {noLoser, onceLost};
    }
};
*/


// counting sort
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> lostTracker(100001, -1);
        for (auto match: matches) {
            auto winner = match[0], loser = match[1];
            if (lostTracker[winner] == -1) lostTracker[winner] = 0;
            if (lostTracker[loser] == -1) lostTracker[loser] = 0;
            lostTracker[loser]++;
        }
        vector<int> noLoser, onceLost;
        for (int i = 0; i < lostTracker.size(); i++)
            if (lostTracker[i] == 1)
                onceLost.push_back(i);
            else if (lostTracker[i] == 0)
                noLoser.push_back(i);
        return {noLoser, onceLost};
    }
};