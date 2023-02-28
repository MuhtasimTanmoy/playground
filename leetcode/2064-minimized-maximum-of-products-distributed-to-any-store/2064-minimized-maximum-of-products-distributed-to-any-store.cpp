class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long l = 0, r = 0;
        for (auto q: quantities) r += q; l = r / n;
        auto getNum = [&](int pivot, int res = 0) {
            for (auto q: quantities) res += q / pivot, res += (q % pivot) ? 1: 0;
            return res;
        };
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (!mid) return r;
            auto val = getNum(mid);
            if (val > n) l = mid + 1; else r = mid;
        }
        return r;
    }
};