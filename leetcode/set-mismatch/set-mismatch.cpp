class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if ( nums[ abs(nums[i]) - 1 ] < 0 ) { 
                result.push_back( abs(nums[i]) );
            }
            
            nums[ abs(nums[i]) - 1 ] = -abs(nums[ abs(nums[i]) - 1 ]);
            
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i+1);
            }
        }
        
        return result;
    }
};