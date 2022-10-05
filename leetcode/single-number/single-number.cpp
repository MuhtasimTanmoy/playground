class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(auto &num: nums) a ^= num;
        return a;
    }
};