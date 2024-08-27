class Solution {
public:
    int minOperations(vector<int>& nums) {
        auto look_for = 0, res = 0;
        for (auto num: nums) 
            if (num == look_for) res++, look_for = !look_for;
        return res;
    }
};