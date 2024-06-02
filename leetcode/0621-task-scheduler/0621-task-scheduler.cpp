// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
        
//         vector<int> tasks_freq(26, 0);
//         for (auto task: tasks) tasks_freq[task - 'A']++;
        
//         priority_queue<pair<int, int>> pq;
//         for (auto i = 0; i < tasks_freq.size(); i++) 
//             if (tasks_freq[i])
//                 pq.push({tasks_freq[i], i});
        
//         int res = 0;
//         vector<int> tasks_last_seen(26, -n);
//         while (pq.size()) {
//             auto [count, task_id] = pq.top(); pq.pop();
//             auto last_seen_at = tasks_last_seen[task_id];
//             res = max(res, last_seen_at + n) + 1;
//             tasks_last_seen[task_id] = res;
//             cout<<count<<" "<<task_id<<" "<<last_seen_at<<" "<<res<<endl;
//             if (count - 1 > 0) pq.push({count - 1, task_id});
//         }
//         return res;
        
//     }
// };


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> tasks_freq(26, 0);
        for (auto task: tasks) tasks_freq[task - 'A']++;
        
        priority_queue<int> pq;
        for (auto i = 0; i < tasks_freq.size(); i++) 
            if (tasks_freq[i])
                pq.push(tasks_freq[i]);
        
        int res = 1;
        while (pq.size()) {
            auto round = n + 1;
            vector<int> done;
            while (round--) {
                if (pq.size()) {
                    auto take = pq.top(); pq.pop();
                    if (--take) 
                        done.push_back(take);
                }
                if (pq.size() || done.size()) res++;
            }
            cout<<res<<endl;
            for (auto now: done) pq.push(now);
        }
        return res;
        
    }
};