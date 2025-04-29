class Solution {
public:
    int numberOfArrays(vector<int>& D, int l, int u) {
        long long now = 0, lowest = 0, highest = 0;
        for (auto d: D) 
            now += d,
            lowest = min(lowest, now),
            highest = max(highest, now);

        auto change = l - lowest;
        lowest += change;
        highest += change;

        if (highest <= u) return u - highest + 1;
        return 0;
    }
};