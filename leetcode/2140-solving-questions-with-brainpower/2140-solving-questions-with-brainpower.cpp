class Solution {
public:
    long long mostPoints(vector<vector<int>>& qs) {
        unordered_map<int, long long> bag;
        function<long long(int)> go = [&](auto idx) {
            if (idx >= qs.size()) return 0LL;
            if (bag.count(idx)) return bag[idx];
            auto with = qs[idx][0] + go(idx + qs[idx][1] + 1),
                 without = go(idx + 1);
            return bag[idx] = max(with, without);
        };
        return go(0);
    }
};