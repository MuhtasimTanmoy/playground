class Solution {
public:
    // bool hasMatch(string s, string p) {
    //     int l = 0, r = p.size() - 1;
    //     for (auto c: s) {
    //         if (p[l] == '*') break;
    //         if (c == p[l]) l++;
    //     }
    //     for (int e = s.size() - 1; e >= l; e--) {
    //         if (p[r] == '*') break;
    //         if (s[e] == p[r]) r--;
    //     }
    //     return r == l;
    // }

    bool hasMatch(string s, string p) {
        int x = p.find("*");
        string b = p.substr(0, x), e = p.substr(x + 1);
        int i = s.find(b), j = s.rfind(e);
        return i != -1 && j != -1 && i + b.size() <= j;
    }
};