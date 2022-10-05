class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valToIndexMapping;
        for (int i = 0; i < nums.size(); i++) {
            auto curr = nums[i];
            auto lookingFor = target - curr;
            if (valToIndexMapping.count(lookingFor)) {
                auto prevIndex = valToIndexMapping[lookingFor];
                return {prevIndex, i};
            } else valToIndexMapping[curr] = i;
        }
        return {-1, -1};
    }
};