class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1, minDistance = INT_MAX;
        for (int i = size(points) - 1; i >= 0; i--) {
            auto point = points[i];
            if (point[0] != x && point[1] != y) continue;
            
            auto distance = abs(point[0] - x) + abs(point[1] - y);
            if (distance <= minDistance) {
                index = i;
                minDistance = distance;
            }
        }
        return index;
    }
};