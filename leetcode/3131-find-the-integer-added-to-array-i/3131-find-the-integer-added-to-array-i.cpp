class Solution {
public:
    int addedInteger(vector<int>& l, vector<int>& r) {
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        return r.front() - l.front();
    }
};