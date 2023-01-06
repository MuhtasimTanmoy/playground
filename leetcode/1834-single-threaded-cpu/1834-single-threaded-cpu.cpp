class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res, idx(tasks.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), 
             [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
        
        for (long i = 0, time = 1; i < idx.size() || !pq.empty();) {
            
            for (; i < idx.size() && tasks[idx[i]][0] <= time; ++i)
                pq.push({tasks[idx[i]][1], idx[i]});
            
            if (pq.size()) {
                auto [procTime, j] = pq.top(); pq.pop();
                time += procTime;
                res.push_back(j);
            } else time = tasks[idx[i]][0];
        }
        return res;
    }
};