class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int limit = 1, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            limit -= nums[i] == 0;
            if (limit < 0) limit += nums[j++] == 0;
        }
        return nums.size() - j;
    }
};