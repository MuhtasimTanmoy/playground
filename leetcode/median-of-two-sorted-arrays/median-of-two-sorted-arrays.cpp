
// O( m + n )

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

// Binary O(log(m+n)) solution

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = n1;
        while(low <= high) {
            int cut1 = (low + high)>>1;
            int cut2 = (n1 + n2 + 1)/2 - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            //Solution lies here 
            if(left1 <= right2 and left2 <= right1) {
                if((n1+n2)%2 == 1)
                    return max(left1, left2);
                else
                    return (max(left1, left2) + min(right1, right2))/2.0;
            }
            
            else if(left1 > right2)
                high = cut1 - 1;
            
            else
                low = cut1 + 1;
        }
        return 0;
    }
};