class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& l, vector<int>& r) {
        unordered_set<int> lbag(l.begin(), l.end()), 
                           rbag(r.begin(), r.end());
        int l_count = 0, r_count = 0;
        for (auto i: l) if (rbag.count(i)) l_count++;
        for (auto i: r) if (lbag.count(i)) r_count++;
        return {l_count, r_count};
    }
};