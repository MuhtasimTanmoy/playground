class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<array<long, 3>, 
                      vector<array<long, 3>>, 
                      greater<array<long, 3>>> avail, busy;
        
        vector<int> res;
        for (int i = 0; i < servers.size(); ++i) avail.push({ 0, servers[i], i });
        
        for (long t = 0; t < tasks.size(); ++t) {
            while (busy.size() && (busy.top()[0] <= t || avail.empty())) {
                auto [time, w, i] = busy.top(); busy.pop();
                avail.push({ time <= t ? 0 : time, w, i });
            }
            auto [time, w, s] = avail.top(); avail.pop();
            busy.push({ max(time, t) + tasks[t], w, s });
            res.push_back(s);
        }
        return res;
    }
};