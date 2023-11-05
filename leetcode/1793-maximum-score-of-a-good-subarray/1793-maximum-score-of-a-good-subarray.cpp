/*
35 / 72 test cases passed.
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        unordered_set<string> dp;
        auto gen_key = [](auto l, auto r) {
            return to_string(l) + "-" + to_string(r);
        };
        
        int n = nums.size(), res = 0;
        function<void(int, int, int)> go = [&](auto l, auto r, auto min_in) {
            if (l < 0 || r == n) return;
            res = max(res, min_in * (r - l + 1));
            
            auto key = gen_key(l, r);
            if (dp.count(key)) return;
            
            if (l > 0) go(l - 1, r, min(min_in, nums[l - 1]));
            if (r < n - 1) go(l, r + 1, min(min_in, nums[r + 1]));
            
            dp.insert(key);
        };
        
        go(k, k, nums[k]);
        return res;
    }
};

55 / 72 test cases passed.
class Solution {
public:
    int maximumScore(vector<int>& nums, int k, int res = INT_MIN) {
        for (int i = 0; i < nums.size(); i++) {
            int min_in_range = INT_MAX;
            for (int j = i; j < nums.size(); j++) {
                min_in_range = min(min_in_range, nums[j]);
                if (i <= k && j >= k) 
                    res = max(res, min_in_range * (j - i + 1));
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k], l = k - 1, r = k + 1, n = nums.size(), curr_min = nums[k];
        while (l >= 0 && r < n) {
            auto l_val = nums[l], r_val = nums[r];
            curr_min = min(curr_min, l_val > r_val ? nums[l--]: nums[r++]);
            res = max(res, curr_min * (r - l - 1));
        }
        while (l >= 0)
            curr_min = min(curr_min, nums[l--]), res = max(res, curr_min * (r - l - 1));
        while (r < n)
            curr_min = min(curr_min, nums[r++]), res = max(res, curr_min * (r - l - 1));
        return res;
    }
};