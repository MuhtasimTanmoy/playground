class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        long long res = 0;
        while (left < right) {
            auto numStr = to_string(nums[left++]) + to_string(nums[right--]);
            res += stoi(numStr);
        }
        if (left == right) res += nums[left];
        return res;
    }
};