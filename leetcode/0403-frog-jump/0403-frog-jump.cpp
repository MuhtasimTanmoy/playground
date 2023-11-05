class Solution {
public:
    bool canCross(vector<int>& s) {
        int n = s.size();
        
        unordered_map<string, bool> dp;
        auto gen_key = [](auto a, auto b) { return to_string(a) + "-" + to_string(b); };
        
        function<bool(int, int)> go = [&](auto i, auto k) {
            if (i == n - 1) return true;
            
            auto key = gen_key(i, k);
            if (dp.count(key)) return dp[key];
            
            bool is_possible = false;
            for (auto jump = k - 1; jump <= k + 1; jump++) {
                if (jump <= 0) continue;
                auto find = s[i] + jump;
                auto idx = lower_bound(s.begin() + i, s.end(), find) - s.begin();
                if (idx < n && s[idx] == find) is_possible |= go(idx,  jump);
            }
            return dp[key] = is_possible;
        };
        
        return go(0, 0);
    }
};