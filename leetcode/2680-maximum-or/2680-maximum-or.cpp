class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> r(n);
        for (int i = n - 2; i >= 0; i--)
            r[i] = nums[i + 1] | r[i + 1];
        long long res = 0;
        for (int i = 0, l = 0; i < n; i++) 
            res = max(res, l | ( (long long) nums[i] << k) | r[i]),
            l |= nums[i];
        return res;
    }
};