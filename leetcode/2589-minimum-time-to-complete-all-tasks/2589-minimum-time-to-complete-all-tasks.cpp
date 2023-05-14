// 679 / 1059 test cases passed.
class Solution {
public:
    // int findMinimumTime(vector<vector<int>>& tasks) {
    //     sort(tasks.begin(), tasks.end(), [](auto l, auto r) {
    //         return l[0] < r[0];
    //     });
    //     int res = 0;
    //     vector<int> prev = {0, 0, 0};
    //     for (auto task: tasks) {
    //         if (task[1] <= prev[1]) {
    //             res += max(task[2] - prev[2], 0);
    //             task[1] = prev[1];
    //         } else if (task[0] >= prev[1]) res += task[2];
    //         else if (task[0] < prev[1]) {
    //             auto satisfied = min(prev[1] - task[0], prev[2]);
    //             task[0] = prev[1];
    //             task[2] = max(task[2] - satisfied, 0);
    //             res += task[2];
    //         }
    //         prev = task;
    //     }
    //     return res;
    // }
    
    int findMinimumTime(vector<vector<int>>& tasks) {
        int line[2001] = {};
        sort(begin(tasks), end(tasks), [](const auto &t1, const auto &t2){
            return t1[1] < t2[1];
        });
        for (auto &t : tasks) {
            int st = t[0], end = t[1], d = t[2];
            d -= count(begin(line) + st, begin(line) + end + 1, true);
            for (int i = end; d > 0; --i)
                d -= !line[i],
                line[i] = true;
        }
        return count(begin(line), end(line), true);
    }
};