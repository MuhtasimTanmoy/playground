class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long two = 0;
        for (auto num: nums) two ^= num;
        long long last_diff_bit = two & -two;
        
        int f = 0, s = 0;
        for (auto num: nums) 
            if (num & last_diff_bit) f ^= num;
            else s ^= num;
        return {f, s};
    }
};