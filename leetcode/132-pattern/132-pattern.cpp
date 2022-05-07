class Solution {
public:
   bool find132pattern(vector<int>& nums) {
        vector<int> sk;
        int third = INT_MIN;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (third > nums[i])
                return true;
            while (sk.size() && sk.back() < nums[i]) {
                third = sk.back();
                sk.pop_back();
            }
            sk.push_back(nums[i]);
        }
        return false;
    }
};