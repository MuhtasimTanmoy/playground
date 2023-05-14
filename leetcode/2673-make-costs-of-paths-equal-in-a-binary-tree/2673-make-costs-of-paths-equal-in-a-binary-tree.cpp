// https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/discuss/3494844/C%2B%2B-Java-Python3-Short-DFS
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        function<int(int)> go = [&](auto i) {
            if (i >= cost.size()) return 0;
            auto l = go(2 * i + 1), r = go(2 * i + 2);
            res += abs(l - r);
            return cost[i] + max(l, r);
        };
        go(0);
        return res;
    }
};