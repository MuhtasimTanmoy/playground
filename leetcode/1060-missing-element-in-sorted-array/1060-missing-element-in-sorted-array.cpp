class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int now = nums[0] + k - 1;
        for (auto num: nums) {
            if (num > now) return now;
            else now++;
        }
        return now;
    }
};