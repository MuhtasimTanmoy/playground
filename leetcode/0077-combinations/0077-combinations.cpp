class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> builder;
        function<void(int, int)> go = [&](auto i, auto to) {
            if (to == k) {
                res.push_back(builder);
                return;
            }
            for (int j = i; j <= n; j++) 
                builder.push_back(j),
                go(j + 1, to + 1),
                builder.pop_back();
        };
        go(1, 0);
        return res;
    }
};