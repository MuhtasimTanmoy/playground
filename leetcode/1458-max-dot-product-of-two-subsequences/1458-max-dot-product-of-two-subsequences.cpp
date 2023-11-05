class Solution {
public:
    int maxDotProduct(vector<int>& l, vector<int>& r) {
        unordered_map<string, int> dp;
        auto gen_key = [](int a, int b) {
            return to_string(a) + "-" + to_string(b);
        };
        function<int(int, int)> go = [&](auto i, auto j) {
            if (i == l.size() || j == r.size()) return 0;
            
            auto key = gen_key(i, j);
            if (dp.count(key)) return dp[key];
            
            auto val = l[i] * r[j];
            
            int res = INT_MIN;
            if (val > 0) res = val + go(i + 1, j + 1);
            res = max(res, go(i + 1, j));
            res = max(res, go(i, j + 1));
            return dp[key] = res;
        };
        
        auto res = go(0, 0);
        if (res == 0) {
            int calc = INT_MIN;
            for (auto up: l)
                for (auto down: r)
                    calc = max(calc, up * down);
            return calc;
        }
        return res;
    }
};