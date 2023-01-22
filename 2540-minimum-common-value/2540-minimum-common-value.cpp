class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i1 = 0, i2 = 0; i1 < nums1.size() && i2 < nums2.size();) {
            if (nums1[i1] == nums2[i2]) return nums1[i1];
            else if (nums1[i1] > nums2[i2]) i2++;
            else i1++;
        }
        return -1;
    }
};