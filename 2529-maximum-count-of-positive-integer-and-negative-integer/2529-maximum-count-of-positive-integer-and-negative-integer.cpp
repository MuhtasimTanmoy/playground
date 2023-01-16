class Solution {
public:
    int maximumCount(vector<int>& nums, 
                     int pos = 0, int neg = 0) {
        for (auto num: nums) 
            pos += num > 0,
            neg += num < 0;
        return max(pos, neg);
    }
};