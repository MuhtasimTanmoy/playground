class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alti = 0, res = 0;
        for (auto g: gain) {
            alti += g;
            res = max(res, alti);
        }
        return res;
    }
};