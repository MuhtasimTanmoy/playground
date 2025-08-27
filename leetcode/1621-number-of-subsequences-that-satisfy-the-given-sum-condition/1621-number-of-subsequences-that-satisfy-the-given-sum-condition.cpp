class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1000000007;
        vector<int> pre = {0, 1};
        for (auto i = pre.size(); i <= nums.size(); ++i)
            pre.push_back((pre.back() << 1) % mod);
        
        sort(begin(nums), end(nums));
        for (int i = 0, j = nums.size() - 1; i <= j; ++i) {
            while (i <= j && nums[i] + nums[j] > target) --j;
            res = (res + pre[j - i + 1]) % mod;
        }
        return res;
    }
};