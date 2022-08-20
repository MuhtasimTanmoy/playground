class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int counter = 0;
        int limit = nums.size() >> 1;
        for (auto num: nums) if (num == target) {
            counter++;
            if (counter > limit) return true;
        }
        return false;
    }
};