class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> count(101, 0);
        int res = 0;
        for (auto num: nums) res += count[num], count[num]++;
        return res;
    }
};