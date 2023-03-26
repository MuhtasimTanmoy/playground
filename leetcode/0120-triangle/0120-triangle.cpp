class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        auto gen_key = [](auto l, auto... r) {
            return (to_string(l) + ... + ("-" + to_string(r)));
        };
        unordered_map<string, int> cache;
        
        auto max_depth = t.size();
        function<int(int, int)> go = [&](auto idx, auto depth) {
            if (depth == max_depth) return 0;
            
            auto key = gen_key(idx, depth);
            if (cache.count(key)) return cache[key];
            
            auto curr = t[depth][idx];
            auto l = curr + go(idx, depth + 1), 
                 r = curr + go(idx + 1, depth + 1);
            
            return cache[key] = min(l, r);
        };
        return go(0, 0);
    }
};