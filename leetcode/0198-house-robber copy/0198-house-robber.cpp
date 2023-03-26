/*
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(100, -1);
        function<int(int)> go = [&](int idx) {
            if (idx >= nums.size()) return 0;
            if (cache[idx] != -1) return cache[idx];
            
            auto res = go(idx + 1);
            res = max(go(idx + 2) + nums[idx], res);
            return cache[idx] = res;
        };
        return go(0);
    }
};
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev_l = 0, prev = 0;
        for (auto num: nums) {
            auto cache = prev;
            prev = max(prev, prev_l + num);
            prev_l = cache;
        }
        return prev;
    }
};