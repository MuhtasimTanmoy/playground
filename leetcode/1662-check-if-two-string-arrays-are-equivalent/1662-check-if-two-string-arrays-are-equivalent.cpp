class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& ls, vector<string>& rs) {
        int l = 0, li = 0, r = 0, ri = 0;
        
        auto get_next_l = [&]() {
            if (li == ls[l].size()) li = 0, l++;
            if (l == ls.size()) return '0';
            return ls[l][li++];
        };
        auto get_next_r = [&]() {
            if (ri == rs[r].size()) ri = 0, r++;
            if (r == rs.size()) return '0';
            return rs[r][ri++];
        };
        
        while (true) {
            auto q = get_next_l(), r = get_next_r();
            if (q == '0' && r == '0') return true;
            if (q != r) return false;
        }
        return false;
    }
};