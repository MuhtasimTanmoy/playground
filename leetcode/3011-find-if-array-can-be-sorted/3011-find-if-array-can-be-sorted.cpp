class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> setbitcount;
        for (auto num: nums) setbitcount.push_back(__builtin_popcount(num));
        
        for (auto i = 1; i < nums.size(); i++) {
            auto j = i - 1;
            while (j >= 0 && nums[j] > nums[j + 1]) {
                if (setbitcount[j] != setbitcount[j + 1]) return false;
                swap(nums[j], nums[j + 1]);
                swap(setbitcount[j], setbitcount[j + 1]);
                j--;
            }
        }
        return true;
    }
};