class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0), cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        auto gen_key = [](auto l, auto ... r) {
            return (to_string(l) + ... + (to_string(r)));
        };
        unordered_map<string, int> um;
        
        function<int(int, int)> go = [&](auto start, auto end) {
            if (end - start == 1) return 0;
            auto key = gen_key(start, end);
            if (um.count(key)) return um[key];
            
            int len = cuts[end] - cuts[start], res = INT_MAX;
            for (auto i = start + 1; i < end; i++) {
                auto temp = go(start, i) + go(i, end);
                res = min(res, temp);
            }
            return um[key] = len + res;
        };
        return go(0, cuts.size() - 1);
    }
};