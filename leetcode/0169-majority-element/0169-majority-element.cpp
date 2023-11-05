/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, now;
        for (auto num: nums) {
            if (count == 0) now = num;
            count += num == now ? 1: -1;
        }
        return now;
    }
};