class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        auto target = nums.size();
        for (auto i = 0; i < nums.size(); i++, target--) {
            if (target <= nums[i]) {
                if (i == 0) return target;
                else if (nums[i - 1] < target) return target; 
            }
        }
        return target ? target: -1;
    }
};