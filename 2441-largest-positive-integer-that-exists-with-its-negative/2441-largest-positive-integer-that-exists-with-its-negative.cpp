class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        unordered_set<int> bag(nums.begin(), nums.end());
        for (auto num: nums) if (bag.count(-num)) return num;
        return -1;
    }
};