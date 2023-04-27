// Gets TLE
/*
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        unordered_map<string, int> cache;
        auto gen_key = [](auto l, auto ... r) {
            return (to_string(l) + ... + ("-" + to_string(r)));  
        };
        
        function<int(int, int, bool)> go = [&](auto curr, auto left, 
                                                           auto took) {
            if (left == 0) return 1;
            if (left < 0 || curr > left) return 0;
            
            auto key = gen_key(curr, left, took);
            if (cache.count(key)) return cache[key];
            
            auto take = go(curr + 1, left - curr, true),
                 not_take = took ? 0: go(curr + 1, left, false);
            
            return cache[key] = take + not_take;
        };
        
        return go(1, n, false);
    }
};
*/

// https://leetcode.com/problems/consecutive-numbers-sum/discuss/129033/C%2B%2B-2-lines-O(sqrt-n)

class Solution {
public:
    int consecutiveNumbersSum(int N, int res = 0) {
        for (auto n = 2; n * (n + 1) / 2 <= N; ++n) 
            res += (N - n * (n + 1) / 2) % n == 0 ? 1 : 0;
        return res + 1;
    }
};