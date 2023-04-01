class Solution {
public:
    vector<int> arraysIntersection(vector<int>& a, 
                                   vector<int>& b, 
                                   vector<int>& c) {
        vector<int> res;
        int i = 0, j = 0, k = 0;
        while (i < a.size() && j < b.size() && k < c.size()) {
            if (a[i] == b[j] && b[j] == c[k]) {
                res.push_back(a[i]);
                i++, j++, k++;
            } else {
                auto max_in = max({a[i], b[j], c[k]});
                if (a[i] < max_in) i++;
                if (b[j] < max_in) j++;
                if (c[k] < max_in) k++;
            }
        }
        return res;
    }
};