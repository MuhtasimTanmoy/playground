class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int n = g.size(), res = 0;
        unordered_set<char> bag;
        for (int i = n - 1, till = 0; i >= 0; i--) {
            bag.insert(g[i].begin(), g[i].end());
            
            till = max(till, (int) bag.size());
            if (i - 1 >= 0) res += t[i - 1] * till;
            res += g[i].size();
        }
        return res;
    }
};