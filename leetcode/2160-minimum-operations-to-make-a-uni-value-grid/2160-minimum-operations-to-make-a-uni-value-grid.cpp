class Solution {
public:
    int minOperations(vector<vector<int>>& G, int x) {
        vector<int> L;
        int rem = G.front().front() % x;
        for (auto r: G)
            for (auto c: r) {
                if (c % x != rem) return -1;
                L.push_back(c);
            }
        sort(L.begin(), L.end());
        int m = L.size() >> 1, mid = L[m], res = 0;
        for (auto l: L) res += abs(l - mid) / x;
        return res;
    }
};