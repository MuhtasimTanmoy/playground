// class Solution {
// public:
//     bool isCovered(vector<vector<int>>& ranges, int left, int right) {
//         vector<int> rangemark(51, 0);
//         for (auto range: ranges)
//             for (int i = range[0]; i <= range[1]; i++)
//                 rangemark[i] = 1;    
//         for (int i = left; i <= right; i++) if (!rangemark[i]) return false;
//         return true;
//     }
// };

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for (auto &range: ranges) {
            if (range[0] <= left && left <= range[1]) {
                left = range[1]+1;
            }
        }
        return left > right;
    }
};