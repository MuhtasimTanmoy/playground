class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = 0;
        int distance = INT_MAX;
        
        for(int &i: nums)
            if (abs(i) <= distance) {
                result = abs(i) == distance ? max(result, i) : i;
                distance = abs(i);
            }
        
        return result;
    }
};