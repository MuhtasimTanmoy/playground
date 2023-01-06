class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i = lastPos - 1; i >= 0; i--) 
            if (i + nums[i] >= lastPos)
                lastPos = i;
        return lastPos == 0;
    }
};