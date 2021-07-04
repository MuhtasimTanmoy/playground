class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if ( m == 0 ) { 
            nums1 = nums2;
            return;
        }
        
        int num1Itr = m - 1;
        int num2Itr = n;
        
        int totalItr = m + n - 1;
        
        while(num2Itr--) {
            
            if ( num1Itr < 0 || nums1[num1Itr] < nums2[num2Itr] ) {
                nums1[totalItr] = nums2[num2Itr];
            } else {
                nums1[totalItr] = nums1[num1Itr];
                num1Itr--;
                num2Itr++;
            }
            
            totalItr--;
        }
    }
};