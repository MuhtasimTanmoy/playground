class Solution {
public:
    long long maximumPoints(vector<int>& E, int curr) {
        sort(E.begin(), E.end());
        long long res = 0;
        for (long long l = 0,  r = E.size() - 1; l <= r; r--) {
            if (curr >= E[l])
                res += curr / E[l], curr = curr % E[l];
            if (!res) break;
            curr += E[r];
        }
        return res;
    }
};