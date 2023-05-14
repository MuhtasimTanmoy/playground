class Solution {
public:
    bool checkIfCanBreak(string l, string r) {
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        bool l_valid = true, r_valid = true;
        for (auto i = 0; i < l.size(); i++) {
            if (l_valid && l[i] > r[i]) l_valid = false;
            if (r_valid && r[i] > l[i]) r_valid = false;
        }
        if (l_valid || r_valid) return true;
        return false;
    }
};