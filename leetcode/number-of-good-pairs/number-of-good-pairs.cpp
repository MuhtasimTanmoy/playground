class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        vector<int> count(100 + 1, 0);
        for(auto num: nums) {
            result += count[num];
            count[num]++;
        }
        return result;
    }
};