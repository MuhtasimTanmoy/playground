class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counter; int res = 0;
        for (auto num: nums) counter[num]++;
        optional<pair<int, int>> prev;
        for (auto [key, value]: counter) {
            if (prev) {
                auto isValid = abs(key - prev->first) == 1;
                if (isValid) res = max(value + prev->second, res);
            }
            prev = make_pair(key, value);
        }
        return res;
    }
};