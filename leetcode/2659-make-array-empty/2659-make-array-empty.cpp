class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<int> idx(nums.size(), 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](auto l, auto r) {
            return nums[l] < nums[r];
        });
        long long res = nums.size();
        for (int i = 1; i < nums.size(); i++)
            if (idx[i-1] > idx[i])
                res += nums.size() - i;
        return res;
    }
};