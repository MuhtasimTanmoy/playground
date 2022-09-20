class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a,const vector<int>& b) {
            return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
        });
        
        vector<int> markedInvalid = {-1, -1};
        for(int i = 1; i < size(intervals); i++) 
            if (intervals[i-1][1] >= intervals[i][0]) {
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
                intervals[i-1] = markedInvalid;
            }
        
        int j = 0;
        for(int i = 0; i < size(intervals); i++) {
            if (intervals[i][0] == markedInvalid[0]) continue;
            intervals[j++] = intervals[i];
        }
        intervals.resize(j);
        return intervals;
    }
};