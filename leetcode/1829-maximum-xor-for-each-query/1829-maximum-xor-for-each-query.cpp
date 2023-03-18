class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int max_bit, int x_or = 0) {
        int max_num = pow(2, max_bit) - 1;
        for (auto num: nums) x_or ^= num;
        vector<int> res;        
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(x_or ^ max_num);
            x_or ^= nums[i];
        }
        return res;
    }
};