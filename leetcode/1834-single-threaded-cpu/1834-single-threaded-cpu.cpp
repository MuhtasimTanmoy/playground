// class Solution {
// public:
//     vector<int> getOrder(vector<vector<int>>& t, vector<int> res = {}) {
        
//         for (int i = 0; i < t.size(); i++) t[i].push_back(i);
//         sort(t.begin(), t.end(), [](auto l, auto r) {
//             return l[0] < r[0];
//         });

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
//         for (long long i = 0, to = 0; i < t.size() || pq.size(); ) {
//             while (i < t.size() && t[i][0] <= to) {
//                 auto duration = t[i][1], idx = t[i][2];
//                 pq.push({duration, idx});
//                 i++;
//             }
//             if (pq.empty()) to = t[i][0];
//             else {
//                 auto up = pq.top(); pq.pop();
//                 res.push_back(up.second);
//                 to += up.first;
//             }
//         }
//         return res;
//     }
// };


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