class Solution {
public:
    int maxScore(vector<int>& nums, int res = 0, long long pre = 0) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (auto num: nums) pre += num, res += pre > 0;
        return res;
    }
};