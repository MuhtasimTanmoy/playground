class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> store;
        auto pow_score = [](int i, int steps = 0) {
            while (i != 1) i = (i & 1) ? 3 * i + 1: i >>= 1, steps++;
            return steps;
        };
        for (int i = lo; i <= hi; i++) store.push_back({pow_score(i), i});
        sort(store.begin(), store.end());
        return store[k - 1].second;
    }
};