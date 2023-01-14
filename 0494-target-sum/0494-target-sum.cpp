class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> cache;
        function<int(int, int)> go = [&](auto index, auto sum) {
            if (index == nums.size()) return !sum ? 1: 0;
            
            auto key = to_string(index) + "-" + to_string(sum);
            if (cache.count(key)) return cache[key];
            
            return cache[key] = go(index + 1, sum - nums[index]) 
                                + go(index + 1, sum + nums[index]);
        };
        return go(0, target);
    }
};