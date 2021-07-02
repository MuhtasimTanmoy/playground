class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for( int num: nums) {
            sum += num % 2 ? 0 : num;
        }
        
        vector<int> result;
        
        for( auto query: queries) {
            
            int newValue = query[0];
            int index = query[1];
            
            sum -= nums[index] % 2 ? 0 : nums[index];
            nums[index] = nums[index] + newValue;
            sum += nums[index] % 2 ? 0 : nums[index];
            
            result.push_back(sum);
        }
        
        return result;
        
    }
};