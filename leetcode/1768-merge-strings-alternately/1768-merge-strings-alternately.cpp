class Solution {
public:
    string mergeAlternately(string l, string r) {
        string res = "";
        for (auto i = 0; i < max(l.size(), r.size()); i++) {
            if (i < l.size()) res += l[i];
            if (i < r.size()) res += r[i];
        }
        return res;
    }
};