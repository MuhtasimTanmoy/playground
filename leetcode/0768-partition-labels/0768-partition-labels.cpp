// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         vector<pair<int, int>> ranges(26, {-1, -1});
//         for (auto i = 0; i < s.size(); i++) {
//             auto &[from, to] = ranges[s[i] - 'a'];
//             if (from == - 1) from = i, to = i; else to = i;
//         }
//         ranges.push_back({s.size(), s.size()});

//         // ranges.erase(remove(ranges.begin(), 
//         //                     ranges.end(), 
//         //                     make_pair(-1, -1)), 
//         //                     ranges.end());

//         ranges.erase(remove_if(ranges.begin(), 
//                                ranges.end(),
//                                [](auto p) { return p == make_pair(-1, -1); }),
//                                ranges.end());
//         sort(ranges.begin(), ranges.end());

//         vector<int> res; int limit = -1;
//         for (auto [from, to]: ranges) {
//             if (limit != -1 && from > limit) res.push_back(limit + 1);
//             limit = max(limit, to);
//         }
//         for (int i = res.size() - 1; i > 0; i--) res[i] -= res[i-1];
//         return res;
//     }
// };

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); ++i) last[s[i] - 'a'] = i;

        vector<int> partitions;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) 
                partitions.push_back(end - start + 1),
                start = i + 1;
        }

        return partitions;
    }
};