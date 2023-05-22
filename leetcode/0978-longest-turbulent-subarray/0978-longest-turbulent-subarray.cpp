class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int inc = 1, dec = 1, res = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i])
                inc = dec + 1,
                dec = 1;
            else if (a[i - 1] > a[i])
                dec = inc + 1,
                inc = 1;
            else 
                inc = 1, dec = 1;
            res = max(res, max(inc, dec));
        }
        return res;
    }
};