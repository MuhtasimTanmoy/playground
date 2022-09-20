class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
                
        vector<int>  result;
        
        for(int i = 0; i < size(nums) ; i++) {
            int indexToMark = abs(nums[i]) - 1;
            if (nums[indexToMark] > 0) {
                nums[indexToMark]*= -1;
            } 
        }
        
        for(int i = 0; i < size(nums) ; i++) {
            if (nums[i] > 0) {
               result.push_back(i+1);
            }
        }
        
        return result;
    }
};