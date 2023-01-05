class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int curr = 0, res = 0;
        while (curr < points.size()) {
            auto next = curr + 1;
            auto limit = points[curr][1];
            while (next < points.size() && points[next][0] <= limit) 
                limit = min(limit, points[next++][1]);
            res++;
            curr = next;
        }
        return res;
    }
};