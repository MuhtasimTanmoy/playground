class Solution {
public:
    int numSplits(string s, int res = 0) {
        unordered_map<char, int> l, r;
        for (auto c: s) r[c]++;
        for (auto c: s) {
            l[c]++;
            if (--r[c] == 0) r.erase(c);
            if (l.size() == r.size()) res++;
        }
        return res;
    }
};