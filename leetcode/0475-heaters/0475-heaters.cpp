class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxRadius = 0;
        sort(heaters.begin(), heaters.end());
        for (const auto& house : houses) {
            int distance1 = INT_MAX, distance2 = INT_MAX;
            auto larger = lower_bound(heaters.begin(), heaters.end(), house);
            if (larger != heaters.end()) distance1 = *larger - house;
            if (larger != heaters.begin()) {
                auto smaller = larger - 1;
                distance2 = house - (*smaller);
            }
            maxRadius = max(maxRadius, min(distance1, distance2));
        }
        
        return maxRadius;
    }
};