class Solution {
public:
   int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, n = nums.size(), selected = 0;
        if (nums[0]) ans = 1;
        for (int i = 0; i < n; i++) {
            selected++;
            if (selected > nums[i]) 
                if (i + 1 < n && selected < nums[i+1]) ans++; 
                else if ( i + 1 == n ) ans++;
        }
        return ans;
    }
};