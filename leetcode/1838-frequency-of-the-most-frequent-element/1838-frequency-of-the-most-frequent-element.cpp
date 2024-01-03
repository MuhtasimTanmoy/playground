class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0, right = 0, total = 0, result = 0;
        while (right < size(nums)) {
            total += nums[right];
            while ((right - left + 1) * nums[right] - total > k) 
                total -= nums[left], left++;         
            result = max(result, right++ - left + 1);
        }
        return result;
    }
};