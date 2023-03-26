class Solution {
public:
    int minCapability(vector<int>& A, int k) {
        int l = 1, r = 1e9, n = A.size();
        while (l < r) {
            auto m = ( l + r) / 2, take = 0;
            for (int i = 0; i < n; ++i) if (A[i] <= m) take++, i++;
            if (take >= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};