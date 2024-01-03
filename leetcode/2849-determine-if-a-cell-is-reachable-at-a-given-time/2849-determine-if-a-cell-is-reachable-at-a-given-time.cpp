class Solution {
public:
    bool isReachableAtTime(int x, int y, int tx, int ty, int t) {
        auto min_dist = max(abs(x - tx), abs(y - ty));
        if (!min_dist && t == 1) return false;
        return min_dist <= t;
    }
};