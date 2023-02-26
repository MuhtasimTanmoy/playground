class Solution {
public:
    int minDistance(string l, string r) {
        
        auto key = [&](int i, int j) {
            return to_string(i) + "-" + to_string(j);
        };
        
        unordered_map<string, int> cache;
        
        function<int(int, int)> go = [&](auto i, auto j) {
            if (i == 0) return j;
            if (j == 0) return i;
            auto k = key(i, j);
            if (cache.count(k)) return cache[k];
            
            if (l[i-1] == r[j-1]) return cache[k] = go(i-1, j-1);
            else {
                auto insert = go(i, j - 1), del = go(i - 1, j);
                auto repl = go(i-1, j-1);
                return cache[k] = min(min(repl, insert) , del) + 1;
            }
        };
        
        return go(l.size(), r.size());
    }
};