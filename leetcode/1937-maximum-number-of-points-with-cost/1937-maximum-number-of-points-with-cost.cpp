class Solution {
public:
    /*
    long long maxPoints(vector<vector<int>>& p, long long res = 0) {
        auto gen_key = [](auto l, auto ...r) { return (to_string(l) + ... + (to_string(r))); };
        unordered_map<string, long long> c;
        function<long long(int, int)> go = [&](auto r, auto prev_c) -> long long {
            if (r == p.size()) return 0;
            
            auto key = gen_key(r, prev_c);
            if (c.count(key)) return c[key];
            
            long long res = 0;
            for (int i = 0; i < p[r].size(); i++) {
                long long to_be = p[r][i] + go(r + 1, i) - abs(prev_c - i);
                res = max(res, to_be);
            }
            return c[key] = res;
        };
        for (int i = 0; i < p[0].size(); i++) res = max(res, p[0][i] + go(1, i));
        return res;
    }
    */
    
    long long maxPoints(vector<vector<int>>& p, long long res = 0) {
        vector<long long> dp(p[0].size());
        for (auto &row: p) {
            vector<long long> temp(p[0].size());
            for (long long i = 0, run_max = 0; i < row.size(); i++) {
                run_max = max(run_max - 1, dp[i]);
                temp[i] = run_max;
            }
            for (long long i = row.size() - 1, run_max = 0; i >= 0; i--) {
                run_max = max(run_max - 1, dp[i]);
                temp[i] = max(run_max, temp[i]) + row[i];
            }
            swap(temp, dp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};