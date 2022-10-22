class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0, res = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            auto val = (sum + i) / (i + 1);
            res = max(val, res);
        }
        return res;
    }
};