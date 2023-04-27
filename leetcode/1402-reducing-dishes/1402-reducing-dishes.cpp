// Recursive
/*
class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        auto gen_key = [](auto l, auto ... r) {
            return (to_string(l) + ... + ( "-" + to_string(r)));
        };
        unordered_map<string, int> cache;
        sort(s.begin(), s.end());
        function<int(int, int)> go = [&](auto i, auto cnt) {
            if (i == s.size()) return 0;
            
            auto key = gen_key(i, cnt);
            if (cache.count(key)) return cache[key];
            
            auto not_taken = go(i + 1, cnt);
            auto taken = s[i] * cnt + go(i + 1, cnt + 1);
            return cache[key] = max(not_taken, taken);
        };
        return go(0, 1);
    }
};
*/

// Iterative
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> prev(satisfaction.size() + 2, 0);
        
        for (int index = satisfaction.size() - 1; index >= 0; index--) {
            vector<int> dp(satisfaction.size() + 2);
            
            for (int time = 1; time <= satisfaction.size(); time++) 
                dp[time] = max(satisfaction[index] * time 
                               + prev[time + 1], prev[time]);
            
            prev = dp;
        }
        return prev[1];
    }
};