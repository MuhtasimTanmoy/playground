class Solution {
public:
    int numRescueBoats(vector<int>& P, int limit) {
        sort(P.begin(), P.end());
        int l = 0, r = P.size() - 1, res = 0;
        while (l <= r) {
            auto total = l == r ? P[l]: P[l] + P[r];
            if (total <= limit)
                res++,
                l++,
                r--;
            else 
                res++,
                r--;
        }
        return res;
    }
};