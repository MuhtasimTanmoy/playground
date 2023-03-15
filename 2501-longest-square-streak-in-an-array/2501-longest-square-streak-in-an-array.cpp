/*
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        auto gen_key = [](long long i, 
                          long long j) { return to_string(i) + "-" + to_string(j); };
        unordered_map<string, long long> cache;
        
        function<long long(long long, long long)> go = 
            [&](auto idx, auto prev) -> long long {
            
            if (idx == nums.size()) return 0;
            
            auto key = gen_key(idx, prev);
            if (cache.count(key)) return cache[key];
                
            long long res = go(idx + 1, nums[idx]);
            if (prev) res = max(res, go(idx + 1, prev));
            
            if (prev * prev != (long long) nums[idx]) return res;
            return cache[key] = max(res, 1 + go(idx + 1, nums[idx]));
        };
        
        auto res =  go(0LL, 0LL);
        return res ? res + 1: -1;
    }
};
*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums, int res = 0) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, int> dp;
        for (int i = nums.size() - 1; i >= 0; i--) {
            long long curr = nums[i], next = curr * curr;
            dp[curr] = dp.count(next) ? dp[next] + 1: 0;
            res = max(res, dp[curr]);
        }
        return res ? res + 1: -1;
    }
};