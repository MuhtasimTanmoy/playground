class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs, int limit = -1001, int  res = 0) {
        sort(pairs.begin(), pairs.end(),[](auto a, auto b) { return a[1] < b[1]; });
        for (auto pair: pairs) if (pair[0] > limit) res++, limit = pair[1];
        return res;
    }
};