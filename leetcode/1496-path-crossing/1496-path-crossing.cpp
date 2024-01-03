class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> at = {0, 0};
        set<pair<int, int>> bag;
        bag.insert(at);
        
        for (auto now: path) {
            if (now == 'N') at.first++;
            else if (now == 'S') at.first--;
            else if (now == 'E') at.second--;
            else at.second++;
            
            if (bag.count(at)) return true;
            bag.insert(at);
        }
        return false;
    }
};