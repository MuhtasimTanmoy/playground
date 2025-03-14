class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& l, vector<vector<int>>& r) {
        map<int, int> tracker;
        for (auto i: l) tracker[i.front()] += i.back();
        for (auto i: r) tracker[i.front()] += i.back();
        vector<vector<int>> res;
        for (auto [key, val]: tracker) res.push_back({key, val});
        return res;
    }
};