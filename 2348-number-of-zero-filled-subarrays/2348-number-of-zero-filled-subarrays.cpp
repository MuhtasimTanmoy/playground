class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int consCount = 0;
        for (auto num: nums)
            if (!num) {
                if (!consCount) consCount = 1; else consCount++;
                res += consCount;
            } else consCount = 0;
        return res;
    }
};