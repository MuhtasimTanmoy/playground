class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& R) {
        vector<pair<int, int>> x, y;
        for (auto r: R) {
            auto x_1 = r[0], x_2 = r[2];
            auto y_1 = r[1], y_2 = r[3];

            x.push_back({x_1, x_2});
            y.push_back({y_1, y_2});
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        auto right = x.front().second, div = 0;
        for (auto i = 1; i < x.size(); i++) {
            if (x[i].first >= right) div++;
            right = max(right, x[i].second);
            if (div == 2) return true;
        }

        auto up = y.front().second, udiv = 0;
        for (auto i = 1; i < y.size(); i++) {
            if (y[i].first >= up) udiv++;
            up = max(up, y[i].second);
            if (udiv == 2) return true;
        }

        return false;
    }
};