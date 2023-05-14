class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size(), res = 0;
        for (int i = 1; i < n; i++) res = res ^ d[i-1];
        return d.back() == res;
    }
};