class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int _min = INT_MAX;
        int _max =  INT_MIN;
        
        vector<string> result;

        if ( nums.size() == 0 ) {
             return result;
        }
        
        nums.push_back(nums[nums.size() - 1]); 
        
        for( int i = 0; i < nums.size() - 1; i++ ) {
            
            long long distance = (long long)nums[i+1] - (long long)nums[i];
            
            if( distance == 1 ) {
                _min = min(nums[i], _min);
                _max = max(nums[i+1], _max);
            } else {
                
                string s;
                
                if ( _min == INT_MAX && _max == INT_MIN ) {
                    s = to_string(nums[i]);
                } else {
                    s = to_string(_min) + "->" + to_string(_max); 
                }
                
                result.push_back(s);
                
                _min = INT_MAX;
                _max = INT_MIN;
            }
        }
        
        return result;
    }
};