class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        int lo = 1, hi = 1e9;
        auto cal = [&](int p, int ops = 0) {
            for (auto n: nums) ops += (n - 1) / p;
            return ops;
        };
        while (lo < hi) {
            auto m = lo + (hi - lo) / 2;
            auto trgt = cal(m);
            if (trgt > maxOps) lo = m + 1;
            else hi = m;
        }
        return hi;
    }
};