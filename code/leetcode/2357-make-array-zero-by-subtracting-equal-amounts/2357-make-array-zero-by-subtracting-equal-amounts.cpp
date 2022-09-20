class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> bag(nums.begin(), nums.end());
        bag.erase(0);
        return bag.size();
    }
};