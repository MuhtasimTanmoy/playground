class Solution {
public:
    int countSubmatrices(vector<vector<int>>& g, int k) {
        int res = 0;
        for (auto i = 0; i < g.size(); i++)
            for (auto j = 0; j < g.back().size(); j++) {
                auto l = j ? g[i][j - 1] : 0,
                     u = i ? g[i - 1][j] : 0;
                auto corner = (j && i) ? g[i - 1][j - 1] : 0;
                g[i][j] = l + u - corner + g[i][j];
                if (g[i][j] > k) break;
                res++;
            }
        return res;
    }
};