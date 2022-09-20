class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        for (int i = 0; i < nums.size() - 1; i++) 
            for (int j = i + 1; j < nums.size(); j++) {
                auto distance = nums[j] - nums[i];
                if (distance > 0) res = max(res, distance);
            }
        return res;
    }
};