class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK, long long res = 0) {
        for (int i = 0, j = -1, in = -1, ax = -1; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) in = ax = j = i;
            in = nums[i] == minK ? i: in;
            ax = nums[i] == maxK ? i: ax;
            res += min(in, ax) - j;
        }
        return res;
    }
};