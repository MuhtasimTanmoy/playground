/*
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        unordered_map<string, int> dp;
        auto gen_key = [](int a, int b, int c, int d) {
            return to_string(a) + "-" + to_string(b) + "-" + to_string(c) + "-" + to_string(d);
        };
        
        int n = nums.size();
        function<int(int, int, int, int)> go = [&](auto i, auto prev, auto count, auto left) {
            if (i == n || left < 0) return count;
            
            auto key = gen_key(i, prev, count, left);
            if (dp.count(key)) return dp[key];
            
            int res = 0;
            if (nums[i] == prev) res = max(res, go(i + 1, prev, count + 1, left));
            else res = max(res, go(i + 1, prev, count, left - 1));
            
            res = max(res, go(i + 1, nums[i], 1, left));
            return  dp[key] = res;
        };
        
        return go(1, nums.front(), 1, k);
    }
};
*/

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        unordered_map<int, vector<int>> counter;
        for (int i = 0; i < nums.size(); i++)
            counter[nums[i]].push_back(i);
        
        int res = 0;
        for (auto [num, ids]: counter) {
            int j = 0, i = 1;
            for (int bal = k; i < ids.size(); i++) {
                bal -= ids[i] - ids[i-1] - 1;
                if (bal < 0)
                    bal += ids[++j] - ids[j-1] - 1;
            }
            res = max(res, i - j);   
        }
        return res;
    }
};