// if two intervals are overlapping, we want to remove the interval that has the longer end point -- the longer interval will always overlap with more or the same number of future intervals compared to the shorter one

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int prevMax = INT_MIN, res = 0;
        for (auto interval: intervals) {
            auto left = interval[0], right = interval[1];
            if (left < prevMax) res++;
            else prevMax = max(prevMax, right);
        }
        return res;
    }
};