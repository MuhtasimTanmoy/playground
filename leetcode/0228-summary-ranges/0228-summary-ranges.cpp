class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        auto builder = [&](int l, int r) {
            if (l < r) return to_string(nums[l]) + "->" + to_string(nums[r]);
            return to_string(nums[l]);
        };
        for (int i = 0; i < n; ) {
            int l = i, m = i, r = i + 1;
            while (r < n && nums[m] + 1 == nums[r]) m++, r++;
            res.push_back(builder(l, m));
            i = r;
        }
        return res;
    }
};