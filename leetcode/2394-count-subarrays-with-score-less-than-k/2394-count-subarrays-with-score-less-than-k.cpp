class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, sum = 0;
        for (auto i = 0, j = 0; i < nums.size(); i++) {   
            sum += nums[i];
            while (sum * (i - j + 1) >= k) sum -= nums[j++];
            res += i - j + 1;
        }
        return res;
    }
};