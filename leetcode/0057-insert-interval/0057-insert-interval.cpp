// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& to_insert) {
//         vector<vector<int>> res;
//         bool inserted = false;
//         for (auto i = 0; i < intervals.size(); i++) {
//             auto interval = intervals[i];
//             auto from = interval.front(), to = interval.back();
//             if (res.size() && res.back().back() >= from) 
//                 res.back()[1] = max(to, res.back()[1]);
//             else if (inserted == false && res.size() && to_insert.front() <= res.back().back())
//                 res.back()[1] = max(to_insert.back(), res.back()[1]),
//                 inserted = true,
//                 i--;
//             else if (inserted == false && to_insert.back() < from) 
//                 res.push_back(to_insert),
//                 res.push_back(interval),
//                 inserted = true;
//             else
//                 res.push_back(interval);
//         }
//         if (!inserted && (res.empty() 
//                           || res.back().back() < to_insert.front())) res.push_back(to_insert);
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for (size_t i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0])
                result.push_back(intervals[i]);
            else if (intervals[i][0] > newInterval[1])
                result.push_back(newInterval),
                newInterval = intervals[i];  
            else if (intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
                newInterval[0] = min(intervals[i][0], newInterval[0]),
                newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        result.push_back(newInterval); 
        return result;
    }
};