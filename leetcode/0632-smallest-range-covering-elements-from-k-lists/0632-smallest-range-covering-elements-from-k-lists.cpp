class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> list;
        int id = 0;
        for (auto l: nums) {
            id++;
            for (auto i: l) list.emplace_back(i, id);
        }
        int lower = 0, upper = INT_MAX;
        sort(list.begin(), list.end());
        unordered_map<int, int> counter;
        for (auto l = 0, r = 0; r < list.size(); r++) {
            auto [val, id] = list[r];
            counter[id]++;
            
            while (counter.size() == nums.size()) {
                auto [pre_val, pre_id] = list[l++];
                auto now = val - pre_val;
                if ( (upper - lower) > now ) lower = pre_val, upper = val;
                if (--counter[pre_id] == 0) counter.erase(pre_id);
            }
        }
        return {lower, upper};
    }
};