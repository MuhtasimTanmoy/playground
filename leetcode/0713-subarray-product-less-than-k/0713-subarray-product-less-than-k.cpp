class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        for (auto l = 0, r = 0, product = 1; r < nums.size(); r++) {
            product *= nums[r];
            while (l < r && product >= k) 
                product /= nums[l++];
            if (product < k) res += r - l + 1;
        }
        return res;
    }
};