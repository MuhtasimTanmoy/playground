/*
class Solution {
    const int MOD = 1e9 + 7;
public:
    int numWays(int steps, int len) {
        unordered_map<string, int> um;
        auto gen_key = [](auto i, auto j) { return to_string(i) + "-" + to_string(j); };
        function<int(int, int)> go = [&](auto i, auto has) {
            if (!i && !has) return 1;
            if (!has) return 0;
            
            auto key = gen_key(i, has);
            if (um.count(key)) return um[key];
            
            auto right = i < (len - 1) ? go(i + 1, has - 1) % MOD: 0,
                 left = i > 0 ? go(i - 1, has - 1) % MOD: 0,
                 stay = go(i, has - 1) % MOD;
            return um[key] = ((right + left) % MOD + stay) % MOD;
        };
        return go(0, steps);
    }
};
*/

class Solution {
    const int MOD = 1e9 + 7;
public:
    int numWays(int steps, int len) {
        int sz = min(steps / 2 + 1, len);
        vector<int> v1(sz + 2), v2(sz + 2);
        v1[1] = 1;
        while (steps--) {
            for (auto i = 1; i <= sz; ++i)
                v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007;
            swap(v1, v2);
        }
        return v1[1];
    }
};