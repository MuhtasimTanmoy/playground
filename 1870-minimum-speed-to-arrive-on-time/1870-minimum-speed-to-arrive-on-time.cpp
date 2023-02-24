class Solution {
public:
    int minSpeedOnTime(vector<int>& d, double hour) {
        int lo = 1, hi = 10000001;
        auto calc = [&](int p, double r = 0) {
            for (int i = 0; i < d.size() - 1; i++) 
                r += (int) (d[i] + p - 1) / p;
            r += (double) d.back() / p;
            return r;
        };
        while (lo < hi) {
            auto m = lo + (hi - lo) / 2;
            auto p = calc(m);
            if (p > hour) lo = m + 1; else hi = m;
        }
        return lo == 10000001 ? -1: lo;
    }
};