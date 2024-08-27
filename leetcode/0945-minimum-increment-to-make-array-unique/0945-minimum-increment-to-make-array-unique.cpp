class Solution {
public:
    int minIncrementForUnique(vector<int>& N) {
        sort(N.begin(), N.end());
        int res = 0;
        for (auto i = 1; i < N.size(); i++) {
            auto need = N[i-1] + 1 - N[i];
            if (need > 0) res += need, N[i] += need;
        }
        return res;
    }
};