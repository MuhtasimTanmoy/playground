class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> bag;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= k) bag.insert(nums[i]);
            if (bag.size() == k) return nums.size() - i;
        }
        throw "error";
    }
};