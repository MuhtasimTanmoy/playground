// Gets TLE
class Solution {
public:
    // int minGroups(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end(), [&](auto a, auto b) {
    //         return a[0] < b[0];
    //     });
    //     vector<vector<int>> lasts;
    //     for (auto interval: intervals) {
    //         auto l = interval[0], r = interval[1];
    //         if (lasts.empty()) lasts.push_back({r});
    //         else {
    //             bool inserted = false;
    //             for (auto &last: lasts) 
    //                 if (l > last.back()) {
    //                     last.push_back(r);
    //                     inserted = true;
    //                     break;
    //                 }
    //             if (inserted == false) lasts.push_back({r});
    //         }
    //     }
    //     return lasts.size();
    // }
    
    int minGroups(vector<vector<int>>& ints) {
        sort(begin(ints), end(ints));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &i : ints) {
            if (pq.size() && pq.top() < i[0]) pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};