class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        auto target = nums[0] + k;
        for (int i = 1; i < nums.size(); i++) 
            if (target >= nums[i]) target++;
            else break;
        return target;
    }
};