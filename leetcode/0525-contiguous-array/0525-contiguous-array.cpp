class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> val_to_index;
        val_to_index[0] = -1;
        
        auto res = 0;
        for (auto i = 0, zero = 0; i < nums.size(); i++) {
            zero += nums[i] ? 1: -1;
            if (val_to_index.count(zero))
                res = max(res, i - val_to_index[zero]);
            else val_to_index[zero] = i;
        }
        return res;
    }
};