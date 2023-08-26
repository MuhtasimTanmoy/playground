class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        auto can_take = [](string& s, int bitmask) {
            if (s.size() != set<char>(s.begin(), s.end()).size()) return false;
            for (auto c: s) if (bitmask & (1 << (c - 'a'))) return false;
            return true;
        };
        
        auto mark = [](string& s, int bitmask) {
            for (auto c: s) bitmask |= 1 << (c - 'a');
            return bitmask;
        };
        
        unordered_map<string, int> dp;
        auto gen_key = [](int a, int b) {
            return to_string(a) + "-" + to_string(b);
        };
        
        function<int(int, int)> go = [&](auto i, auto bitmask) {
            if (i == arr.size()) return 0;
            
            auto key = gen_key(i, bitmask);
            if (dp.count(key)) return dp[key];
            
            auto count = go(i + 1, bitmask);
            auto can = can_take(arr[i], bitmask);
            if (can) {
                auto new_bitmask = mark(arr[i], bitmask);
                int val = arr[i].size() + go(i + 1, new_bitmask);
                count = max(count, val);
            }
            return dp[key] = count;
        };
        return go(0, 0);
    }
};