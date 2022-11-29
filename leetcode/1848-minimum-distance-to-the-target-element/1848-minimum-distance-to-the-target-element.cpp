class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minRes = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) 
                minRes = min(minRes, abs(i - start));
        return minRes;
    }
};