class Solution {
public:
    int sumOfGoodNumbers(vector<int>& N, int k) {
        int res = 0;
        for (auto i = 0; i < N.size(); i++) {
            auto li = i - k, ri = i + k, is_met = 0;;
            if (li < 0 || N[li] < N[i]) is_met++;
            if (ri >= N.size() || N[ri] < N[i]) is_met++;
            if (is_met == 2) res += N[i];
        }
        return res;
    }
};