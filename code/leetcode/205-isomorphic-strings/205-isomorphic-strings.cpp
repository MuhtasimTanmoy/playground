class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> scount(128, -1), tcount(128, -1);
        for (int i = 0; i < s.size(); ++i) {
            auto schar = s[i], tchar = t[i];
            if (scount[schar] == -1) {
                scount[schar] = tchar;
                if (tcount[tchar] != -1) return false;
                else tcount[tchar] = schar;
            } else if (scount[schar] != tchar) return false;
        }
        return true;
    }
};