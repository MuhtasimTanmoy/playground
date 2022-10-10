class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int durationMax = 0, prevTime = 0;
        int res = 0;
        for (auto log: logs) {
            auto id = log[0];
            auto endTime = log[1];
            
            auto duration = endTime - prevTime; prevTime = endTime;
            
            if (duration >= durationMax) {
                res = duration == durationMax ? min(res, id): id;
                durationMax = duration;
            }
        }
        return res;
    }
};