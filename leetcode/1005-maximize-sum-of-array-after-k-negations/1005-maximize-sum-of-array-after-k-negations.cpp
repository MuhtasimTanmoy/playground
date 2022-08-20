class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int availed = 0;
        for (int i = 0; i < min(k, (int)nums.size()); i++) 
            if (nums[i] < 0 && ++availed) 
                nums[i] = - 1 * nums[i];
        
        sort(nums.begin(), nums.end());
        if ((k - availed) % 2) nums[0] = -1 * nums[0];
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        return sum;
    }
};