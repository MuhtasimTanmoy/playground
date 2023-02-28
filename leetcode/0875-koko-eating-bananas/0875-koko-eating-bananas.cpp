class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 0;
        auto calc = [&](int trgt, int res = 0) {
            for (auto pile: piles) res += (pile + trgt - 1) / trgt;
            return res;
        };
        for (auto p: piles)  hi = max(hi, p);
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            auto minEat = calc(mid);
            if (minEat > h) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};