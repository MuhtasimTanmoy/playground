class Solution {
public:
    int minimumIndex(vector<int>& N) {
        unordered_map<int, int> counter;
        int maxn = INT_MIN, num = -1;
        for (auto n: N) {
            counter[n]++;
            if (maxn < counter[n]) num = n, maxn = counter[n];
        }
        for (auto i = 0, now = 0; i < N.size() - 1; i++) {
            now += N[i] == num;
            auto l = now > (i + 1) >> 1,
                 r = (maxn - now) > (N.size() - i - 1) >> 1;
            if (l && r) return i;
        }
        return -1;
    }
};