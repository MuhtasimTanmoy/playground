class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        nums.push_back(0);
        vector<int> res(n, -1);
        if (2 * k >= n) return res;
        long long sum = accumulate(nums.begin(), nums.begin() + 2 * k + 1, 0LL);
        for (int i = k; i < n - k; i++) {
            res[i] = sum / (2 * k + 1);
            sum -= nums[i - k];
            sum += nums[i + k + 1];
        }
        return res;
    }
};