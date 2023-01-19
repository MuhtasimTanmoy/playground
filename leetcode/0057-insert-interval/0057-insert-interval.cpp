// thought of binary search bt compaction process is o(n). SO not applicable.
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int left = 0;
//         int right = size(intervals) - 1;
//         while(left < right) {
//             auto mid = left + (right - left) / 2;
//             if (newInterval[0] < intervals[mid][0]) right = mid;
//             else left = mid + 1;
//         }
        
//         if (left) {
//             if (intervals[left - 1][1] >= newInterval[0]) {
//                 intervals[left - 1][1] = max(newInterval[1], intervals[left - 1][1]);
//                 int compaction = left;
//                 while(compaction < size(intervals) && intervals[left - 1][1] >= intervals[compaction][0]) {
//                     intervals[left - 1][1] = max(intervals[compaction][1], intervals[left - 1][1]);
//                     intervals[compaction++] = {-1, -1};
//                 }
//             } else intervals.insert(intervals.begin() + left, newInterval);
//         } else  intervals.insert(intervals.begin() , newInterval);
        
//         int j = 0;
//         for(int i = 0 ; i < size(intervals); i++) {
//             if (intervals[i][0] == -1 && intervals[i][1] == -1) continue;
//             intervals[j++] = intervals[i];
//         }
//         intervals.resize(j);
//         return intervals;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>> res;
//         bool populating = false;
//         bool inserted = false;
//         for(auto curr: intervals) {
//             if (newInterval[0] <= curr[1] && newInterval[1] >= curr[0]) {
//                 newInterval[0] = min(newInterval[0], curr[0]);
//                 newInterval[1] = max(newInterval[1], curr[1]);
//                 populating = true;
//             } else {
//                 if (populating) { res.push_back(newInterval); populating = false; inserted = true; }
//                 res.push_back(curr);
//             }
//         }
//         if (populating || !inserted) { res.push_back(newInterval); inserted = true; }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>> res;
//         int n = intervals.size(), i = 0; bool available = true;
//         while (i < n || available) {
//             vector<int> cur;
//             if (available && (i == n || newInterval[0] < intervals[i][0])) {
//                 cur = newInterval;
//                 available = false;
//             } else cur = intervals[i++];
            
//             if (res.empty() || res.back()[1] < cur[0]) res.push_back(cur);
//             else res.back()[1] = max(res.back()[1], cur[1]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, 
                               vector<int>& newI, 
                               int i = 0) {
        vector<vector<int>> res;
        for (; i < intervals.size() && intervals[i][0] <= newI[1]; i++) 
            if (intervals[i][1] < newI[0]) res.push_back(intervals[i]);
            else {
                newI[0] = min(intervals[i][0], newI[0]);
                newI[1] = max(intervals[i][1], newI[1]);
            }
        res.push_back(newI);
        res.insert(res.end(), intervals.begin() + i, intervals.end());
        return res;
    }
};