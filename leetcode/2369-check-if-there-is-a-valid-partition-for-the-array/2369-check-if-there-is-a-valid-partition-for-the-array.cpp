/*
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        auto len = nums.size();
        unordered_map<int, bool> dp;
        
        auto two = [&](int i) {
            return i + 1 < len && nums[i] == nums[i+1];
        };
        auto three = [&](int i) {
            if (i + 2 >= len) return false;
            auto eq = two(i) && nums[i+1] == nums[i+2];
            auto incr = (nums[i] + 1) == nums[i+1] && (nums[i+1] + 1) == nums[i+2];
            return eq || incr;
        };
        
        function<bool(int)> go = [&](auto i) {
            if (i == len) return true;
            if (dp.count(i)) return dp[i];
            
            bool can = false;
            if (two(i)) can |= go(i + 2);
            if (three(i)) can |= go(i + 3);
            return dp[i] = can;
        };
        return go(0);
    }
};
*/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int len = nums.size();
        auto two = [&](int i) {
            return i + 1 < len && nums[i] == nums[i+1];
        };
        auto three = [&](int i) {
            if (i + 2 >= len) return false;
            auto eq = two(i) && nums[i+1] == nums[i+2];
            auto incr = (nums[i] + 1) == nums[i+1] && (nums[i+1] + 1) == nums[i+2];
            return eq || incr;
        };
        
        vector<int> dp(len + 1); dp[0] = 1;
        for (auto i = 0; i < len; ++i) {
            if (!dp[i]) continue;
            if (two(i)) dp[i + 2] = 1;
            if (three(i)) dp[i + 3] = 1;
        }
        return dp[len];
    }
};