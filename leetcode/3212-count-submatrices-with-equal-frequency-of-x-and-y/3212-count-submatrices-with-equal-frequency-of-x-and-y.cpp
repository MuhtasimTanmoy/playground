class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& G, int res = 0) {
        vector<pair<int, int>> prev(G.back().size(), {0, 0});
        for (auto i = 0; i < G.size(); i++) {
            vector<pair<int, int>> now(G.back().size(), {0, 0});
            for (auto j = 0; j < G.back().size(); j++) {
                auto [x, y] = prev[j];
                if (j) x += now[j - 1].first, y += now[j - 1].second;
                if (j) x -= prev[j - 1].first, y -= prev[j - 1].second;
                
                x += G[i][j] == 'X';
                y += G[i][j] == 'Y';
                now[j] = {x, y};
                if (x && x == y) res++;
            }
            swap(now, prev);
        }
        return res;
    }
};