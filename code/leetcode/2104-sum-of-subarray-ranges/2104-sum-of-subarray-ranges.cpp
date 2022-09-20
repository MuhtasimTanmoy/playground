class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int left = 0, right = 0;
        while(left < size(nums)) {
            int minInSub = INT_MAX;
            int maxInSub = INT_MIN;
            
            left = left;
            right = left;
            
            while(right < size(nums)) {
                minInSub = min(nums[right], minInSub);
                maxInSub = max(nums[right], maxInSub);
                res += (maxInSub - minInSub);
                right++;
            }
            left++;
        }
        return res;
    }
};