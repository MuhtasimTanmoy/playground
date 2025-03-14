class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& G) {
        for (auto i = 0; i < G.size(); i++) {
            vector<int> list; auto x = i, y = 0;
            while (x < G.size() && y < G.back().size()) list.push_back(G[x++][y++]);
            sort(list.begin(), list.end(), greater<int>());

            x = i, y = 0;
            while (x < G.size() && y < G.back().size()) G[x][y] = list[y], x++, y++;
        }
        for (auto j = 1; j < G.back().size(); j++) {
            vector<int> list; auto x = 0, y = j;
            while (x < G.size() && y < G.back().size()) list.push_back(G[x++][y++]);
            sort(list.begin(), list.end());

            x = 0, y = j;
            while (x < G.size() && y < G.back().size()) G[x][y] = list[x], x++, y++;
        }
        return G;
    }
};