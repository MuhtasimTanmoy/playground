class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> bag;
        for (auto num: nums) {
            if (bag.count(num)) return num;
            bag.insert(num);
        }
        throw "Error";
    }
};