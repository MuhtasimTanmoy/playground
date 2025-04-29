class Solution {
public:
    int findMin(vector<int>& N) {
        int l = 0, r = N.size() - 1;
        while (l < r) {
            auto m = l + (r - l) / 2;
            if (N[l] == N[r]) {
                r--;
            } else if (N[l] > N[r] && N[m] >= N[l]) {
                l = m + 1;
            } else r = m;
        }
        return N[r];
    }
};