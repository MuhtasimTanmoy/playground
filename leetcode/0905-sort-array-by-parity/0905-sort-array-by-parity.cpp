/*
check and maintain in a separate array
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int e = 0, o = 0;
        auto is_valid = [&]() { return e < nums.size() && o < nums.size(); };
        while (is_valid()) {
            while (is_valid() && nums[e] % 2 == 1) e++;
            while (is_valid() && nums[o] % 2 == 0) o++;
            if (is_valid()) 
                if (o < e) swap(nums[e++], nums[o++]); else e++;
        }
        return nums;
    }
};