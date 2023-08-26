/*
class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        if (m * k > bloom.size()) return -1;
        
        unordered_map<string, int> dp;
        auto gen_key = [](auto a, auto b) {
            return to_string(a) + "-" + to_string(b);
        };
        
        function<int(int, int)> go = [&](auto idx, auto count) {
            if (count == m) return 0;
            if (idx + k > bloom.size()) return INT_MAX;
            
            auto key = gen_key(idx, count);
            if (dp.count(key)) return dp[key];
            
            auto max_in = *max_element(bloom.begin() + idx, bloom.begin() + idx + k);
            auto not_taken = go(idx + 1, count),
                 taken = max(max_in, go(idx + k, count + 1));
            return dp[key] = min(taken, not_taken);
        };
        
        return go(0, 0);
    }
};
*/

class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        if ((long long) m * k > bloom.size()) return -1;
        
        auto can = [&](int upto) {
            int need = m, adjacent = 0;
            for (auto day: bloom) {
                adjacent = day <= upto ? adjacent + 1: 0;
                if (adjacent == k) adjacent = 0, need--;
            }
            return need <= 0;     
        };
        
        int l = 1, r = 1e9;
        while (l < r) {
            auto m = l + (r - l) / 2;
            if (can(m)) r = m; else l = m + 1;
        }
        return r;
    }
};