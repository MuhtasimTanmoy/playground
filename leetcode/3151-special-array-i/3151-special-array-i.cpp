class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (auto i = 1; i < nums.size(); i++)
            if ((nums[i] & 1) == (nums[i-1] & 1))
                return false;
        return true;
    }
};