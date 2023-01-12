class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<long long> bag;
        long long res = 0, countingSum = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            auto curr = nums[i];
            while (bag.count(curr) || bag.size() == k) {
                auto toErase = nums[j++];
                bag.erase(toErase), countingSum -= toErase;
            }
            bag.insert(curr), countingSum += curr;
            if (bag.size() == k) res = max(res, countingSum);
        }
        return res;
    }
};