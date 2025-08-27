class Solution {
public:
    int possibleStringCount(string W) {
        int res = 1;
        for (auto i = 1; i < W.size(); i++) if (W[i] == W[i-1]) res++;
        return res;
    }
};