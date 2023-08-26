class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int res = 0, max_so_far = 0;
        priority_queue<pair<int, int>> pq;
        for (auto &event: events) {
            while (pq.size() && -pq.top().first < event[0]) 
                max_so_far = max(max_so_far, pq.top().second),
                pq.pop();
            res = max(res, max_so_far + event[2]);
            pq.push({-event[1], event[2]});
        }
        return res;
    }
};