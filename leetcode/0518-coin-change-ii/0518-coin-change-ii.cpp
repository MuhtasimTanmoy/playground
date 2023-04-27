class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        auto gen_key = [](auto l, auto ... r) { 
            return (to_string(l) + ... + ( "-" + to_string(r))); 
        };
        unordered_map<string,int> um;
        
        function<int(int, int)> go = [&](auto i, auto left) {
            if (left == 0) return 1;
            if (i == coins.size() || left < 0) return 0;
            
            auto key = gen_key(i, left);
            if (um.count(key)) return um[key];
            
            int ways = go(i + 1, left);
            ways += go(i, left - coins[i]);
            return um[key] = ways;
        };
        return go(0, amount);
    }
};