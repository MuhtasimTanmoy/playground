class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        for (int i = 2; i < coordinates.size(); i++) {
            auto last = coordinates[i], mid = coordinates[i-1], first = coordinates[i-2];
            auto res = (last[0] - mid[0]) * (mid[1] - first[1]) 
                    == (last[1] - mid[1]) * (mid[0] - first[0]);
            
            if (!res) return false;
        }
        return true;
    }
};