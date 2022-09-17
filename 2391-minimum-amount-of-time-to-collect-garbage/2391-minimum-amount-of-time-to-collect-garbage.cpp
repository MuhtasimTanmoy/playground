class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for (int i = 1; i< travel.size(); i++) travel[i] += travel[i-1];
        int cost = 0; unordered_set<char> bag;
        for (int i = garbage.size() - 1; i >= 0; i--) {
            auto multiples = garbage[i];
            cost += multiples.size();
            for (auto c: multiples) 
                if (!bag.count(c)) {
                    if (i) cost+= travel[i-1];
                    bag.insert(c);
                }
        }
        return cost;
    }
};