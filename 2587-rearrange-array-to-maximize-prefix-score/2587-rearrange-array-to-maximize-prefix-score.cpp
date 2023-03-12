class Solution {
public:
    int maxScore(vector<int>& nums, int res = 0) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long i = 0;
        for (auto num: nums) {
            i += num;
            if (i > 0) res++;
        }
        return res;
    }
};