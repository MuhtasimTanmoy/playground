class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!m) nums1 = nums2;
        
        int num1Itr = m - 1;
        int num2Itr = n - 1;
        int resItr = m + n - 1;
        
        while (num2Itr >=0 && num1Itr >= 0)
            nums1[resItr--] = 
            (nums1[num1Itr] > nums2[num2Itr])
            ? nums1[num1Itr--]
            : nums2[num2Itr--];
        
        cout<<num2Itr<<" "<<num1Itr<<" "<<resItr<<endl;
        while(num2Itr >= 0) nums1[resItr--] = nums2[num2Itr--];
        // while(num1Itr >= 0) nums1[resItr--] = nums1[num2Itr--];
    }
};