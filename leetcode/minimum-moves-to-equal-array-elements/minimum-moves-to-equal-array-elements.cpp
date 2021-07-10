class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int _min = nums[0];
        int sum = 0;
        
        for( int i: nums ) {
            sum += i;
            _min = min(i, _min);
        }
        
        return sum - nums.size() * _min;
    }
};