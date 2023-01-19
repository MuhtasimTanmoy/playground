class Solution {
public:
    int equalSubstring(string s, string t, int maxCost, int res = 0) {
        vector<int> cost(s.size(), 0);
        for (int i = 0; i < s.size(); i++) cost[i] = abs(s[i] - t[i]);
        for (int i = 0, left = 0, counting = 0; i < cost.size(); i++) {
            counting += cost[i];
            while (counting > maxCost) counting -= cost[left++];
            res = max(res, i - left + 1);
        }
        return res;
    }
};