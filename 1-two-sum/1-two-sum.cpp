class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> bag;
        int index = 0;
        for (int i = 0 ; i < size(nums); i++) {
            auto find = target - nums[i];
            if (bag.count(find)) return { bag[find], i};
            else bag[nums[i]] = i;
        }
        return {-1, -1};
    }
};