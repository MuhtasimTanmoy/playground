class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2, int i = 0) {
        int x = 0, y = 0;
        for (int a : nums1) x ^= a;
        for (int b : nums2) y ^= b;
        return (nums1.size() % 2 * y) ^ (nums2.size() % 2 * x);
    }
};