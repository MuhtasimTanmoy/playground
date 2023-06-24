class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] += 1LL * i * x;
            int curr = nums[i];
            for (int k = 0; k < n; k++) {
                curr = min(curr, nums[(i - k + n) % n]);
                res[k] += curr;
            }
        }
        return *min_element(res.begin(), res.end());
    }
};