class Solution {
    
public:
    int maximumSetSize(vector<int>& l, vector<int>& r) {
        unordered_set<int> lbag, rbag;
        for (auto i: l) lbag.insert(i);
        for (auto i: r) rbag.insert(i);
        
        auto len = (l.size() + r.size()) / 2;
        auto one = min(l.size() / 2, lbag.size()) + min(r.size() / 2, rbag.size());
        
        lbag.insert(rbag.begin(), rbag.end());
        auto two =  min(len, lbag.size());
        return min(one, two);
    }
};