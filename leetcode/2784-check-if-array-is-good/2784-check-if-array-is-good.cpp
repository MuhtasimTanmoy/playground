class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) 
            if (nums[i - 1] != i)
                return false;
        return nums.back() == n - 1;
    }
};