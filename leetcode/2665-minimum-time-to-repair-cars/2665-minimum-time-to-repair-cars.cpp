class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1L * ranks[0] * cars * cars;
        while (l < r) {
            auto m = (l + r) / 2;
            long long cur = 0;
            for (auto rank: ranks) cur += (int) sqrt(m / rank);
            if (cur < cars) l = m + 1;
            else r = m;
        }
        return r;
    }
};