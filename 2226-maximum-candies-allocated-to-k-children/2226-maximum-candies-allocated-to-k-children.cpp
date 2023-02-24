class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        int lo = 0, hi = 1e7;
        auto cal = [&](int piv, long long res = 0) {
            for (auto ci: c) res += ci / piv;
            return res;
        };
        while (lo < hi) {
            auto m = (lo + hi + 1) / 2;
            if (!m) return 0;
            auto trgt = cal(m);
            if (trgt >= k) lo = m; else hi = m - 1;
        }
        return hi;
    }
};