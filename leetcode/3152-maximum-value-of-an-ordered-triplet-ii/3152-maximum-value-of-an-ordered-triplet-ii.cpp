class Solution {
public:
    long long maximumTripletValue(vector<int>& N) {
        long long res = 0;
        vector<int> stk;
        for (int i = 0, mx = 0; i < N.size() - 1; i++) {
            while (stk.size() && N[stk.back()] < N[i]) stk.pop_back();
            mx = max(mx, N[stk.size() ? stk.front(): 0] - N[i]);
            res = max(res, 1LL * mx * N[i + 1]);
            stk.push_back(i);
        }
        return res;
    }
};