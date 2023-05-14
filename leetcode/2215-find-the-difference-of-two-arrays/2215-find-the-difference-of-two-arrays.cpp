class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& l, vector<int>& r) {
        unordered_set<int> ls(l.begin(), l.end()), rs(r.begin(), r.end());
        
        vector<int> l_res;
        for (auto i: ls) if (rs.count(i) == 0) l_res.push_back(i);
        
        vector<int> r_res;
        for (auto i: rs) if (ls.count(i) == 0) r_res.push_back(i);
        
        return {l_res, r_res};
    }
};