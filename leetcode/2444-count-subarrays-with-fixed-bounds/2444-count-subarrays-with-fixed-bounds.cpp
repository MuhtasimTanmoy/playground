class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
         long long res = 0;
         for (auto i = 0, bad = -1, l = -1, r = -1; i < nums.size(); i++) {
             if (nums[i] < minK || nums[i] > maxK) bad = i;
             l = nums[i] == minK ? i: l;
             r = nums[i] == maxK ? i: r;
             res += max(0, min(l, r) - bad);
         }
         return res;
    }
};