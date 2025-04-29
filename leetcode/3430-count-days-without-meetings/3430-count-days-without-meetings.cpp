class Solution {
public:
    int countDays(int days, vector<vector<int>>& M) {
        sort(M.begin(), M.end(), [&](auto a, auto b) {
            return a.front() < b.front();
        });
        auto to = 0, res = 0;
        for (auto m: M) {
            auto start = m.front(), end = m.back();
            if (start > to) res += start - to - 1;
            to = max(to, end);
        }
        if (days > to) res += days - to;
        return res;
    }
};