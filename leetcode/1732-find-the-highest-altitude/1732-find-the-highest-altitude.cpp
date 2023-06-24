class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int now_at = 0, res = 0;
        for (auto dir: gain)
            now_at += dir,
            res = max(res, now_at);
        return res;
    }
};