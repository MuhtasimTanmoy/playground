class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        auto target = nums.size();
        for (auto idx = 0; idx < nums.size(); idx++) {
            if (target <= nums[idx]) {
                if (idx) { 
                    if (nums[idx - 1] < target) return target; 
                } else return target;
            }
            target--;
        }
        return target ? target: -1;
    }
};