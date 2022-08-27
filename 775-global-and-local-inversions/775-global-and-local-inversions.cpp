// Gets TLE
/*
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int local = 0, global = 0;
        for (int i = 0; i < nums.size() - 1; i++) 
            for (int j = i + 1; j < nums.size(); j++) 
                if (nums[i] > nums[j]) {
                    if (i + 1 == j) local++;
                    global++;
                }
        return local == global;
    }
};
*/

// A local inversion is also a global inversion. Thus, we only need to check if our permutation has any non-local inversion (A[i] > A[j], i < j) with j - i > 1.

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int minSoFar = INT_MAX;
        for (int i = nums.size() - 1; i >= 2; i--) {
            minSoFar = min(nums[i], minSoFar);
            if (nums[i-2] > minSoFar) return false;
        }
        return true;
    }
};