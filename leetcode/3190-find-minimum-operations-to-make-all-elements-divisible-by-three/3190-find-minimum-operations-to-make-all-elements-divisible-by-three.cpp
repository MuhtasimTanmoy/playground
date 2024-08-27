class Solution {
public:
    int minimumOperations(vector<int>& nums, int res = 0) {
        for (auto &num: nums) num %= 3;
        for (auto num: nums) res += min(3 - num, num);
        return res;
    }
};