class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> char_to_cost;
        for (int i = 0; i < chars.size(); i++)
            char_to_cost[chars[i]] = vals[i];
        auto counting = 0, res = 0;
        for (auto c: s) {
            auto cost = char_to_cost.count(c) ? char_to_cost[c]: c - 'a' + 1;
            counting += cost;
            counting = max(counting, 0);
            res = max(res, counting);
        }
        return res;
    }
};