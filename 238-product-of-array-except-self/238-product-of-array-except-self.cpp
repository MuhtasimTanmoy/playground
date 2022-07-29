class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto all = 1;
        int isZeroPresent = 0;
        for (auto num: nums) {
            if (num) all *= num;
            else isZeroPresent++;
        }
        vector<int> res(size(nums), 0);
        for (int i = 0; i < size(res); i++) res[i] = nums[i] ? 
            (isZeroPresent ? 0: all)/nums[i]: isZeroPresent == 1 ? all : 0;
        return res;
    }
};