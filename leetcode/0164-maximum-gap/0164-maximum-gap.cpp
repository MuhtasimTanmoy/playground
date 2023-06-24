class Solution {
public:
    int maximumGap(vector<int>& n) {
        sort(n.begin(), n.end());
        int res = 0;
        for (int i = 1; i < n.size(); i++) res = max(res, n[i] - n[i-1]);
        return res;
    }
};