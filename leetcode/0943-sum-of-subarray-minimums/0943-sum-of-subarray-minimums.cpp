class Solution {
    const int MOD =  1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& N) {
        N.push_back(0);
        vector<int> stk;
        int res = 0;
        for (auto i = 0; i < N.size(); i++) {
            while (stk.size() && N[stk.back()] > N[i]) {
                auto m = stk.back(); stk.pop_back();
                auto l = m - (stk.size() ? stk.back(): -1), r = i - m;
                res = (res + l * r * 1LL * N[m]) % MOD;
            }
            stk.push_back(i);
        }
        return res;
    }
};