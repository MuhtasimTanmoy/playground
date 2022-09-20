class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       
        int maxElem = -1, secondMaxElem = -1;
        int maxElemIndex = 0, secondMaxElemIndex = 0;
        
        for (int i = 0; i < size(nums); i++ ) {
            if ( nums[i] >= maxElem) {
                secondMaxElem = maxElem;
                secondMaxElemIndex = maxElemIndex;
                maxElem = nums[i];
                maxElemIndex = i;
            } else if (nums[i] > secondMaxElem ) {
                secondMaxElem = nums[i];
                secondMaxElemIndex = i;
            }
        }
        
        return ( secondMaxElem * 2 > maxElem ) ? -1 : maxElemIndex;
    }
};