class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size(), n = nums.size();
        while (l <= r) {
            auto m = l + (r - l) / 2;
            auto is_left_less = m ? nums[m - 1] < nums[m] : true,
                 is_right_less = m < n - 1 ? nums[m + 1] < nums[m] : true;
            
            if (is_left_less && is_right_less) return m;
            else if (is_left_less) l = m + 1;
            else r = m - 1;
        }
        throw "error";
    }
};