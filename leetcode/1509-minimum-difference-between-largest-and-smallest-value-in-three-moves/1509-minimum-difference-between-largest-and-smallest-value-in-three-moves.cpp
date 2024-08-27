class Solution {
public:
    int minDifference(vector<int>& N) {
        int n = N.size(), res = INT_MAX;
        sort(N.begin(), N.end());
        if (n <= 4) return 0;
        for (auto i = n - 4, j = 0; i < n; i++, j++)
            res = min(N[i] - N[j], res);
        return res;
    }
};