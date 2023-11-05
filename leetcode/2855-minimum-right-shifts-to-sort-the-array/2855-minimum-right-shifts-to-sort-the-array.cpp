class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int min_elem = INT_MAX, min_at_index = -1, n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            min_elem = min(min_elem, nums[i]);
            if (min_elem == nums[i]) min_at_index = i;
        }
        for (int i = min_at_index, prev = -1; i < min_at_index + n; i++) {
            auto actual = i % n;
            if (prev > nums[actual]) return -1;
            prev = nums[actual];
        }
        return min_at_index ? n - min_at_index: min_at_index;
    }
};