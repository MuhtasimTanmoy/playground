class Solution {
public:
    int findPeakElement(vector<int>& N) {        
        int l = 0, r = N.size() - 1;
        while (l < r) {
            auto m = l + (r - l) / 2;
            if (N[m + 1] > N[m]) l = m + 1;  else r = m;
        }
        return l;
    }
};