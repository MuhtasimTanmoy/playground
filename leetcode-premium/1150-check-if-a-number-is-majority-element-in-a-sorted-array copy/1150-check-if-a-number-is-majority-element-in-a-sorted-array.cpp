class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), threshold = len / 2 + 1, cnt = 0;
        for (auto num: nums)
            if (num == target) 
                if (++cnt == threshold) return true;
        return false;
    }
};