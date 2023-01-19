class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles, int res = 0, int count = 0) {
        for (auto rectangle: rectangles) {
            auto minSq = min(rectangle[0], rectangle[1]);
            if (minSq > res) { count = 1; res = minSq; }
            else if (minSq == res) count++;
        }
        return count;
    }
};