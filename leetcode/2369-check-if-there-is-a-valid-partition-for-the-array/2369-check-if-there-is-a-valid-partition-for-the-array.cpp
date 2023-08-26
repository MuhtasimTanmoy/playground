class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> dp;
        function<bool(int)> go = [&](auto i) {
            if (i == n) return true;
            if (dp.count(i)) return dp[i];
                
            bool is_possible = false;
            if (i + 1 < n && nums[i] == nums[i + 1]) is_possible |= go(i + 2);
            if (i + 2 < n) {
                 auto three_same = nums[i] == nums[i + 1] && nums[i] == nums[i + 2];
                 auto three_cons = (nums[i] == nums[i + 1] - 1) 
                                && (nums[i + 1] == nums[i + 2] - 1);
                 if (three_same || three_cons) is_possible |= go(i + 3);
             }
            return dp[i] = is_possible;
        };
        return go(0);
    }
};