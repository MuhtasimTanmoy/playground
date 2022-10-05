class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int indexToBeReplaced = 1;
        if ( nums.size() == 0) { indexToBeReplaced = 0; }
        
        for(int i = 1; i < nums.size(); i++) {
            if ( nums[i - 1] == nums[i]) {   
            } else {
                nums[indexToBeReplaced] = nums[i];
                indexToBeReplaced++;
            }
        }
        
        return indexToBeReplaced;
    }
};