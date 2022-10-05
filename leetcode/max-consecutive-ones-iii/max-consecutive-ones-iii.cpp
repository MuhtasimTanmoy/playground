class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size();
        while (right < n) {
            k -= !nums[right++];
            if (k < 0 && !nums[left++]) ++k;
        }
        return right-left;
    }
};