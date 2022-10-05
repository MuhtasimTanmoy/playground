class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
        vector<vector<int>>ans;

        if( nums.size() < 3 )
            return ans;
        
        sort(nums.begin(),nums.end());
        
        int l, r;
        if(nums[0] > 0) return ans;
        
        for(int i=0; i < nums.size(); i++) {

          if( nums[i] > 0 ) break;
            
          if( i > 0 && nums[i] == nums[i-1] ) continue;
            
          l = i + 1, r = nums.size() - 1;
            
          while( l < r ) {
            if( nums[i] + nums[l] + nums[r] == 0 ) {
                ans.push_back( {nums[i], nums[l], nums[r]} );
                while(l < r && nums[l]==nums[l+1]) l++;
                while(l < r && nums[r]==nums[r-1]) r--;
                l++;
                r--;
            } else if( nums[i] + nums[l] + nums[r] > 0 ) r--;
             else if( nums[i] + nums[l] + nums[r] < 0)  l++;
        }
    }
    return ans;
    }
};