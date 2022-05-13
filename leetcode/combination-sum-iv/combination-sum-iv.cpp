class Solution {
    
    int result = 0;
    // void traverse(vector<int>& nums, int target) {
    //     if (!target) { result++; return; }
    //     if (target < 0) return;
    //     for(auto i: nums) traverse(nums, target - i);
    // }
    
    void bottomUp(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        
        for( int i = 1; i <= target; i++ ) {
            for(auto num: nums) 
                if ( i - num >= 0 
                    && dp[i] + dp[i - num] < INT_MAX) 
                dp[i] += dp[i - num];
            
            // for (auto num: dp) cout<<num<<" ";
            // cout<<endl;
        }
        
        result = dp[target];
    }
    
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        // traverse(nums, target);
        bottomUp(nums, target);
        return result;
    }
};