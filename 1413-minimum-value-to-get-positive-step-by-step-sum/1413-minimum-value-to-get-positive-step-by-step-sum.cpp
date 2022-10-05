class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = 0;
        int curr = 0;
        for (auto num: nums) {
            curr += num;
            minVal = min(minVal, curr);
        }
        return abs(minVal) + 1;
    }
};