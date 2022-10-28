// class Leaderboard {
// public:
//     Leaderboard() {
        
//     }
    
//     void addScore(int playerId, int score) {
        
//     }
    
//     int top(int K) {
        
//     }
    
//     void reset(int playerId) {
        
//     }
// };

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */


class Leaderboard {
public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        sortedVal.erase({mapping[playerId], playerId});
        mapping[playerId] += score;
        sortedVal.insert({mapping[playerId], playerId});
    }
    
    int top(int k) {
        int res = 0, c = 0;
        for (auto it = sortedVal.rbegin(); it != sortedVal.rend() 
             && c < k; it++) {
            res += (it->first);
            c++;
        }
        return res;
    }
    
    void reset(int playerId) {
        sortedVal.erase({mapping[playerId], playerId});
        mapping[playerId] = 0;
    } 
private:
    unordered_map<int, int> mapping;
    set<pair<int, int>> sortedVal;
};

