class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> li;
        for (auto log: logs) {
            auto id = log[0], time = log[1];
            li[id].insert(time);
        }
        vector<int> res(k);
        for (auto [key, val]: li) {
            auto uam = val.size();
            if (uam) res[uam-1]++;
        }
        return res;
    }
};


// vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
//     unordered_map<int, unordered_set<int>> m;
//     vector<int> res(k);
//     for (auto &l : logs)
//         m[l[0]].insert(l[1]);
//     for (auto &p : m)
//         ++res[p.second.size() - 1];
//     return res;
// }