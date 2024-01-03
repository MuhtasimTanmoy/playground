class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int upto = nums.size() - 1;
        while (upto >= 0 && nums[upto] >= (total - nums[upto])) 
            total -= nums[upto--];
        return upto > 1 ? total: -1;
    }
};