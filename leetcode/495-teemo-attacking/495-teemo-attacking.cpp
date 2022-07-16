class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int prevEnd = timeSeries[0];
        int res = 0;
        for(auto startTime: timeSeries) {
            auto actualStart = max(startTime, prevEnd);
            auto end = startTime + duration;
            res += (end - actualStart);
            prevEnd = end;
        }
        return res;
    }
};