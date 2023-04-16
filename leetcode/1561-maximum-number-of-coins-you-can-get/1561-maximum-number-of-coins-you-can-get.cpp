class Solution {
public:
    int maxCoins(vector<int>& p, int res = 0) {
        sort(p.begin(), p.end());
        auto cnt = p.size() / 3, itr = p.size() - 2;
        while (cnt--) res += p[itr], itr = itr - 2;
        return res;
    }
};