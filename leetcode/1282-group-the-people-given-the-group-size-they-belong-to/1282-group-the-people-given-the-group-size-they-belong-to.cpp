class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> counter;
        vector<vector<int>> res;
        for (int i = 0; i < groupSizes.size(); i++) {
            auto sz = groupSizes[i];
            counter[sz].push_back(i);
            if (counter[sz].size() == sz) res.push_back(move(counter[sz]));
        }
        return res;
    }
};