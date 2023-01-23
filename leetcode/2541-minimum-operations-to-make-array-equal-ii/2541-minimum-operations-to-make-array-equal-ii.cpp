// If operations supported on both array then this will be perfect
/*
class Solution {
public:
    long long minOperations(vector<int>& nums1, 
                            vector<int>& nums2, 
                            int k, 
                            long long countItr = 0) {
        for (int i = 0; i < nums1.size(); i++) {
            auto diff = abs(nums1[i] - nums2[i]);
            if (diff % k != 0) return false;
            countItr += diff / k;
        }
        return countItr % 2 == 0 ? countItr / 2 : -1;
    }
};
*/

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k,
                            long long absSum = 0, long long sum = 0) {        
        for (int i = 0; i < nums1.size(); i++) {
            auto diff = nums2[i] - nums1[i];
            if (k) {
                if (diff % k != 0) return -1;
                sum += diff;
                absSum += abs(diff) / k;
            } else if (diff) return -1;
        }
        return sum ? -1: absSum >> 1;
    }
};