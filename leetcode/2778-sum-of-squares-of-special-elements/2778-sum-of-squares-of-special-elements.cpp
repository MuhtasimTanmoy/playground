class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (auto i = 1; i <= n; i++) 
            if (n % i == 0)
                res += nums[i-1] * nums[i-1];
        return res;
    }
};