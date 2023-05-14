class Solution {
public:
    int arraySign(vector<int>& nums, int res = 1) {
        for (auto num: nums) {
            if (!num) return 0;
            res *= num > 0 ? 1: -1;
        }
        return res;
    }
};