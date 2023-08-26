/*
2010 / 2013 test cases passed.

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size(), res = INT_MAX;
        for (int i = 0; i < n - x; i++)
            for (int j = i + x; j < n; j++) {
                res = min(res, abs(nums[i] - nums[j]));
                if (!res) return res;
            }
        return res;        
    }
};
*/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int res = INT_MAX;
        for (int i = x; i < nums.size(); i++) {
            s.insert(nums[i-x]);
            auto it = s.upper_bound(nums[i]);
            if (it != begin(s)) 
                res = min(res, abs(*prev(it) - nums[i]));
            if (it != end(s))
                res = min(res, abs(*it - nums[i]));
        }
        return res;
    }
};