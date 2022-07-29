class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> timeline;
        for (auto trip: trips) {
            timeline[trip[1]] += trip[0];
            timeline[trip[2]] -= trip[0];
        }
        int currPassenger = 0;
        for(auto [key,curr]: timeline) {
            currPassenger += curr;
            if (currPassenger > capacity) return false;
        }
        return true;
    }
};