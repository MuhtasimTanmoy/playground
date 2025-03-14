class Solution {
public:
    int minimumRecolors(string B, int k) {
        int res = INT_MAX;
        for (auto i = 0, b = 0; i < B.size(); i++) {
            b += B[i] == 'B';
            if (i >= k) {
                b -= B[i-k] == 'B';
            }
            res = min(k - b, res);
        }
        return res;
    }
};