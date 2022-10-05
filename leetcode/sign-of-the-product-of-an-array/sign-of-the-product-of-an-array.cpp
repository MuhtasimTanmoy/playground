class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for(auto num: nums) {
            if(!num) return num;
            res *= num < 0 ? -1: 1;
        }
        return res ;
    }
};