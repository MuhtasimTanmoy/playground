class Solution {
public:
    int minNumber(vector<int>& l, vector<int>& r) {
        vector<int> cntl(10, 0), cntr(10, 0);
        auto ml = INT_MAX, mr = INT_MAX;
        for (auto i: l) cntl[i]++, ml = min(ml, i);
        for (auto i: r) cntr[i]++, mr = min(mr, i);
        for (int i = 0; i < 10; i++) 
            if (cntl[i] && cntr[i]) return i;
        return min(ml, mr) * 10 + max(ml, mr);
    }
};