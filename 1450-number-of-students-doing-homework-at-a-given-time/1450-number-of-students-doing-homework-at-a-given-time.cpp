class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = 0; i < startTime.size(); i++) {
            auto start = startTime[i], end = endTime[i];
            if (start <= queryTime && end >= queryTime) ans++;
        }
        return ans;
    }
};