class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long back_sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long sum = 0, res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            sum += nums[i];
            back_sum -= nums[i];
            res += sum >= back_sum;
        }
        return res;
    }
};