class Solution {
    
public:
    void allSubSet(vector<int>& nums, 
                   vector<int> current,
                   int index,
                   vector<vector<int>>& subsets) {
        
        if (index == nums.size()) { 
            subsets.push_back(current);
            return;
        }
        
        allSubSet(nums, current, index + 1, subsets);
        current.push_back(nums[index]);
        allSubSet(nums, current, index + 1, subsets);
        current.pop_back();
    }
    
    int subsetXORSum(vector<int>& nums) {
        
        vector<vector<int>> subsets;
        vector<int> current;
        allSubSet(nums, current, 0, subsets);
        
        int sum = 0;
        
        for ( auto x : subsets) {
            int xorResult = 0;
            for( auto i: x) {
                xorResult ^= i;
            }
            sum += xorResult;
        }
        
        return sum;
    }
};