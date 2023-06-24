class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int res = 0;
        for (int i = g[0].size() - 1, h = 0; i >= 0 && h < g.size(); i--) {
            while (h < g.size() && g[h][i] >= 0) h++;
            res += (g.size() - h);
        }
        return res;
    }
};