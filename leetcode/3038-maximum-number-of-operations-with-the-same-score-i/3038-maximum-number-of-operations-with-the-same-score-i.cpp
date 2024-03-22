class Solution {
public:
    int maxOperations(vector<int>& nums) {
        auto target = nums[0] + nums[1];
        for (auto i = 2; i < nums.size(); i += 2) {
            auto now = nums[i] + nums[i+1];
            if (now != target) return i / 2;
        }
        return nums.size() / 2;
    }
};