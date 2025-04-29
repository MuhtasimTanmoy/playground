class Solution {
public:
    int singleNumber(vector<int>& N) {
        int res = 0;
        for (auto n: N) res ^= n;
        return res;
    }
};