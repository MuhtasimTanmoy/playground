class Solution {
public:
    int subarraySum(vector<int>& N) {
        vector<int> sum = {N.front()};
        for (auto i = 1; i < N.size(); i++) sum.push_back(N[i] + sum[i-1]);
        int res = 0;
        for (auto i = 0; i < N.size(); i++) {
            auto l = max(0, i - N[i]);
            res += sum[i] - (l ? sum[l-1] : 0);
        }
        return res;
    }
};