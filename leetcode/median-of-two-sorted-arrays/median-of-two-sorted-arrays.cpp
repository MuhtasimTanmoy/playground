class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int num1Index = 0;
        int num2Index = 0;
        
        auto extractNext = [&]() -> int {
            
            if (num1Index >= nums1.size()) {
                num2Index++;
                return nums2[num2Index - 1];
            }
            
            if (num2Index >= nums2.size()) {
                num1Index++;
                return nums1[num1Index - 1];
            }
            
            if (nums1[num1Index] <= nums2[num2Index]) {
                num1Index++;
                return nums1[num1Index - 1];
            } else {
                num2Index++;
                return nums2[num2Index - 1];
            }
        };
        
                
        int totalCount = nums1.size() + nums2.size();
        bool isOdd = (totalCount % 2);
        
        int targetIndex = (totalCount - 1) / 2;
        int currentItem = 0;
        
        for (int i=0; i< totalCount; i++) {
            currentItem = extractNext();
			if ( i < targetIndex ) continue;
            if (isOdd) {
                return currentItem;
            } else {
                int nextItem = extractNext();
                return (currentItem + nextItem) / 2.0;
            }
        }
        return 0;
    }
};