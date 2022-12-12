/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> greaterTop;
        priority_queue<int, vector<int>, greater<int>> lesserTop;
        bool alternate = false;
        for (auto num: nums1) {
            if (alternate) greaterTop.push(num); else lesserTop.push(num);
            alternate = !alternate;
        }
        for (auto num: nums2) {
            if (alternate) greaterTop.push(num); else lesserTop.push(num);
            alternate = !alternate;
        }
        auto size = nums1.size() + nums2.size();
        if (greaterTop.size() == lesserTop.size()) {
            double item =  greaterTop.top() + lesserTop.top();
            return item / 2.0;
        } else {
            if (greaterTop.size() >= lesserTop.size()) return greaterTop.top();
            else lesserTop.top();
        }
        throw "Error";
    }
};
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1Index = 0, n2Index = 0;
        auto extractNext = [&]() -> int {
            if (n1Index >= nums1.size()) return nums2[++n2Index - 1];
            if (n2Index >= nums2.size()) return nums1[++n1Index - 1];
            if (nums1[n1Index] < nums2[n2Index]) return nums1[++n1Index - 1];
            else return nums2[++n2Index - 1];
        };
                
        int totalCount = nums1.size() + nums2.size();
        bool isOdd = (totalCount & 1);
        
        int targetIndex = (totalCount - 1) / 2;
        int currentItem = 0;
        
        for (int i=0; i< totalCount; i++) {
            currentItem = extractNext();
			if ( i < targetIndex ) continue;
            if (isOdd) 
                return currentItem;
            else {
                int nextItem = extractNext();
                return (currentItem + nextItem) / 2.0;
            }
        }
        return 0;
    }
};