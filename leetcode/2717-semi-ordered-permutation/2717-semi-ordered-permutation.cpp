class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int l = -1, r = -1, n = nums.size();
        for (int i = 0; i < n; i++) 
            if (nums[i] == 1) l = i;
            else if (nums[i] == n) r = i;
        return l + n - r - 1 - (l > r);
    }
};