class Solution {
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        const int MOD = 1e9 + 7;
        auto isIn = [&](int x, int y) {
            if (x < 0 || x >= m) return false;
            if (y < 0 || y >= n) return false;
            return true;
        };
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        auto mk_key = [](int a, int b, int c) {
            return to_string(a) + "-" + to_string(b) + "-" + to_string(c);
        };
        unordered_map<string, int> cache;
        
        function<int(int, int, int)> go = [&isIn, &dirs, 
                                           &go, 
                                           &mk_key, &cache](auto x,
                                                            auto y,
                                                            auto ml) {
            if (!isIn(x, y)) return 1;
            if (!ml) return 0;
            
            auto key = mk_key(x, y, ml);
            if (cache.count(key)) return cache[key];
            
            int res = 0;
            for (auto dir: dirs)
                res = (res + go(x + dir.first, 
                                y + dir.second, 
                                ml - 1)) % MOD;
            return cache[key] = res;
        };
        
        return go(sr, sc, maxMove);
    }
};
