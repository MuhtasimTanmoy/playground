class Solution {
public:
    int findMin(vector<int>& N) {
        int l = 0, r = N.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (N[m] > N[r]) l = m + 1; else r = m;
        }
        return N[l];
    }
};