class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int limit = nums.size() / 3;
        unordered_map<int, int> counter;
        unordered_set<int> bag;
        for (auto num: nums) {
            counter[num]++;
            if (counter[num] > limit) bag.insert(num);
        }
        return vector<int>(bag.begin(), bag.end());
    }
};