class Solution {
public:
    int minimumArea(vector<vector<int>>& G) {
        pair<int, int> x {INT_MAX, 0}, y{INT_MAX, 0};
        for (auto i = 0; i < G.size(); i++)
            for (auto j = 0; j < G.back().size(); j++)
                if (G[i][j]) {
                    x.first = min(j, x.first),
                    x.second = max(j, x.second);
                    
                    y.first = min(i, y.first),
                    y.second = max(i, y.second);
                }
        return ( x.second - x.first + 1) * ( y.second - y.first + 1);
    }
};