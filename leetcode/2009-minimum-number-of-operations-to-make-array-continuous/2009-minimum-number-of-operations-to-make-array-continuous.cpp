class Solution {
public:
    int minOperations(vector<int>& nums) {
        // set<int> s;
        // int res = 0, n = nums.size();
        // for (auto num: nums) if (s.count(num)) res++;
        // while (s.back() - s.front() > n)
            
        int res = INT_MAX, n = nums.size();
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        
        for (int i = 0; i < nums.size(); ++i) {
            int idx = lower_bound(nums.begin(), nums.end(), nums[i] + n) - nums.begin();
            res = min(res, n - (idx - i));
        }
        return res;
    }
};