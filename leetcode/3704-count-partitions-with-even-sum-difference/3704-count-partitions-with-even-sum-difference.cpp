class Solution {
public:
    int countPartitions(vector<int>& N) {
        auto total = accumulate(N.begin(), N.end(), 0), res = 0;
        for (auto i = 0, l = 0; i < N.size() - 1; i++) {
            l += N[i];
            auto r = total - l;
            if (abs(r - l) % 2 == 0) res++;
        }
        return res;
    }
};