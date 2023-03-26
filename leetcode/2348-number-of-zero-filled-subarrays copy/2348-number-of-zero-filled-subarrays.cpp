class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums, long long res = 0, int counting = 0) {
        for (auto num: nums) 
            if (num == 0) res += ++counting; else counting = 0;
        return res;
    }
};