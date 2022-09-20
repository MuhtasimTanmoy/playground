class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for(int i = 1; i < size(intervals); i++) 
            if (intervals[i-1][1] > intervals[i][0]) 
               return false;
        return true;
    }
};