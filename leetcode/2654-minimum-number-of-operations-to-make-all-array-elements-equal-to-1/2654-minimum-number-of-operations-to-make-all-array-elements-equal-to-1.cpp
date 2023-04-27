class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones) return (n - ones);
        
        int ans = INT_MAX;
        for (int l = 0; l < n; ++l) {
            int g = nums[l];
            for (int r = l + 1; r < n; ++r) {
                g = gcd(g, nums[r]);
                if (g == 1) 
                    ans = min(ans, r - l + (n - 1));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};