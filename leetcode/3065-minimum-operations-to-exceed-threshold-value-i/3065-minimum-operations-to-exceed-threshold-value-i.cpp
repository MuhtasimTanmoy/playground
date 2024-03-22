class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for (auto num: nums) res += num < k;
        return res;
    }
};